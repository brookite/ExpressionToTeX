/*!
 * \file
 * \brief Файл с реализацией функций и классов для работы с выражениями и деревом выражения
*/

#include "expressions.h"
#include "operators.h"
#include "exceptions.h"
#include <QList>
#include <QStack>
#include <QRegularExpression>


ExpressionTreeNode::ExpressionTreeNode(QList<ExpressionTreeNode*> children)
{
    this->children = children;
};

ExpressionTreeNode* ExpressionTreeNode::getChild(int index) {
    return children.at(index);
}

int ExpressionTreeNode::getChildrenCount() {
    return children.length();
}

ExpressionTreeNode::~ExpressionTreeNode() {
    for (int i = 0; i < children.length(); i++) {
        delete children.at(i);
    }
}

Operation::Operation(QList<ExpressionTreeNode*> children) : ExpressionTreeNode(children) {

}


Value::Value(ValueType type, QString value) : ExpressionTreeNode({}) {
    this->type = type;
    this->value = value;
}

QString Value::getValue() {
    return value;
}

ValueType Value::getType() {
    return type;
}

QString Value::toTex() {
    return value;
}


Value* recognizeValueToken(QString token) {
    QRegularExpression numeric("^-?[0-9.]+$");
    QRegularExpression identifier("^[A-Za-z][A-Za-z_0-9]*$");

    Value* result = nullptr;
    if (numeric.match(token).hasMatch())
    // токен имеет только арабские цифры (0-9), знак дефиса и точку
    {
        result = new Value(NUMERIC, token);
    }
    else if (identifier.match(token).hasMatch())
    // токен имеет только арабские цифры (0-9), заглавные и строчные символы латинского алфавита,
    // знак нижнего подчеркивания, при этом переменная не может начинаться с цифры, знака нижнего подчеркивания
    {
        result = new Value(IDENTIFIER, token);
    }
    return result;
}


ExpressionTreeNode* buildExpressionTree(QStringList& tokens)
{
    // Выдать ошибку распознавания выражения, если токены не переданы
    if (tokens.size() == 0) {
        throw EmptyExpressionException("Не удалось распознать выражение из входного файла. Вероятно, в нем отсутствуют операнды и операции");
    }

    // Считать стек выражения пустым
    QStack<ExpressionTreeNode*> exprStack;
    for (QString token : tokens) // для каждого токена
    {
        int operandCount;
        if (isOperationToken(token, &operandCount))
        // токен является оператором
        {
            Operation* operation;
            QList<ExpressionTreeNode*> operands;
            for (int i = 0; i < operandCount; i++)
            // повторить по количеству операндов в операции
            {
                if (exprStack.isEmpty()) // в стеке не достаточно операндов для изъятия левого операнда
                {
                    // Выдать ошибку недостатка операнда
                    throw InvalidOperandCountException(QString("Недостаточно операндов для операции \"%1\"").arg(token));
                }
                // Снять очередной операнд с вершины стека
                ExpressionTreeNode* operand = exprStack.top();
                exprStack.pop();
                operands.insert(0, operand);
            }

            // Создать узел операции по снятым со стека операндам
            operation = getOperation(token, operands);

            if (operation == nullptr) // узел операции не был создан
            {
                // Выдать ошибку недопустимой операции
                throw InvalidOperationException(
                    QString("Неверная операция \"%1\", ожидалась одна из допустимых операций. Проверьте правильность записи указанной операции").arg(token));
            }

            // Поместить в стек узел данной операции
            exprStack.push(operation);
        }
        else // токен является значением
        {
            // Распознать тип выражения (числовое или переменная)
            Value* valueNode = recognizeValueToken(token);
            if (valueNode != nullptr) // тип значения распознан
            {
                // Поместить значение в стек
                exprStack.push(valueNode);
            }
            else {
                // Выдать ошибку неверно записанной переменной
                throw InvalidValueException(
                    QString("В выражении неверно задано имя переменной \"%1\"").arg(token)
                    );
            }
        }
    }
    if (exprStack.count() == 1) // в стеке не осталось операций или операндов
    {
        // Считать результатом вершину дерева созданного выражения
        return exprStack.top();
    }
    else {
        // Выдать ошибку не полностью написанного выражения
        throw InvalidOperandCountException("Выражение записано не полностью, проверьте правильность записанного выражения и количество операндов операции");
    }
}

