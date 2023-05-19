/*!
 * \file
 * \brief Файл с реализацией функций, необходимых для работы с поддерживаемыми операциями
*/

#include <QStringList>
#include <QRegularExpression>
#include "operations.cpp"


Operation* getOperation(QString token, QList<ExpressionTreeNode*> operands) {
    Operation* result = nullptr;

    if (operands.length() == 1)
    // передан один операнд
    {
        // Создать узел бинарной операции по операндам и токену, если токен соответствует операции
        ExpressionTreeNode* operand = operands.at(0);
        if (token == "POS") {
            result = new UnaryPlusOperation(operand);
        }
        else if (token == "NEG") {
            result = new UnaryMinusOperation(operand);
        }
        else if (token == "!" || token == "~") {
            result = new LogicalInversionOperation(operand);
        }
        else if (token == "SIN") {
            result = new SinOperation(operand);
        }
        else if (token == "COS") {
            result = new CosOperation(operand);
        }
        else if (token == "TG") {
            result = new TanOperation(operand);
        }
        else if (token == "CTG") {
            result = new CotanOperation(operand);
        }
        else if (token == "ARCSIN") {
            result = new ArcsinOperation(operand);
        }
        else if (token == "ARCCOS") {
            result = new ArccosOperation(operand);
        }
        else if (token == "ARCTG") {
            result = new ArctanOperation(operand);
        }
        else if (token == "ARCCTG") {
            result = new ArccotanOperation(operand);
        }
        else if (token == "LN") {
            result = new NaturalLogOperation(operand);
        }
        else if (token == "LG") {
            result = new DecimalLogOperation(operand);
        }
        else if (token == "ABS") {
            result = new AbsOperation(operand);
        }
        else if (token == "SQRT") {
            result = new SqrtOperation(operand);
        }
        else if (token == "SUM1") {
            result = new SumOperation(operand);
        }
        else if (token == "PROD1") {
            result = new ProdOperation(operand);
        }
    }
    else if (operands.length() == 2)
    // передано два операнда
    {
        // Создать узел бинарной операции по операндам и токену, если токен соответствует операции
        ExpressionTreeNode* leftOperand = operands.at(0);
        ExpressionTreeNode* rightOperand = operands.at(1);

        if (token == "+") {
            result = new PlusOperation(leftOperand, rightOperand);
        }
        else if (token == "-") {
            result = new SubOperation(leftOperand, rightOperand);
        }
        else if (token == "*") {
            result = new MulOperation(leftOperand, rightOperand);
        }
        else if (token == "/") {
            result = new DivOperation(leftOperand, rightOperand);
        }
        else if (token == "<") {
            result = new LessOperation(leftOperand, rightOperand);
        }
        else if (token == ">") {
            result = new GreaterOperation(leftOperand, rightOperand);
        }
        else if (token == "<=") {
            result = new LessEqualOperation(leftOperand, rightOperand);
        }
        else if (token == ">=") {
            result = new GreaterEqualOperation(leftOperand, rightOperand);
        }
        else if (token == "==" || token == "=") {
            result = new EqualOperation(leftOperand, rightOperand);
        }
        else if (token == "!=") {
            result = new NotEqualOperation(leftOperand, rightOperand);
        }
        else if (token == "^") {
            result = new PowOperation(leftOperand, rightOperand);
        }
        else if (token == "%") {
            result = new ModOperation(leftOperand, rightOperand);
        }
        else if (token == "LOG") {
            result = new LogOperation(leftOperand, rightOperand);
        }
        else if (token == "SUB") {
            result = new SubIndexOperation(leftOperand, rightOperand);
        }
        else if (token == "&") {
            result = new LogicalAndOperation(leftOperand, rightOperand);
        }
        else if (token == "|") {
            result = new LogicalOrOperation(leftOperand, rightOperand);
        }
        else if (token == "XOR") {
            result = new LogicalXorOperation(leftOperand, rightOperand);
        }
        else if (token == "FORALL") {
            result = new AllQuantifierOperation(leftOperand, rightOperand);
        }
        else if (token == "EXISTS") {
            result = new ExistQuantifierOperation(leftOperand, rightOperand);
        }
        else if (token == "SUM2") {
            result = new SumOperation(leftOperand, rightOperand);
        }
        else if (token == "PROD2") {
            result = new ProdOperation(leftOperand, rightOperand);
        }
        else if (token == "ROOT") {
            result = new RootOperation(leftOperand, rightOperand);
        }
    }
    else if (operands.length() == 3)
    // передано 3 операнда
    {
        // Создать узел тернарной операции по операндам и токену, если токен соответствует операции
        if (token == "SUM") {
            result = new SumOperation(operands.at(0), operands.at(1), operands.at(2));
        }
        else if (token == "PROD") {
            result = new ProdOperation(operands.at(0), operands.at(1), operands.at(2));
        }
    }

    return result;
}


bool isOperationToken(QString token, int * operandsCount) {
    const QStringList binaryOperators = {
        "+", "-", "*", "/", "<", ">", "<=", ">=", "=", "==", "%",
        "!=", "^", "LOG", "SUB", "&", "|", "XOR", "FORALL", "EXISTS",
        "ROOT", "SUM2", "PROD2"
    };

    const QStringList unaryOperators = {
        "POS", "NEG", "!", "~", "SIN", "COS", "TG",
        "CTG", "ARCSIN", "ARCCOS", "ARCTG", "ARCCTG",
        "ABS", "LN", "LG", "SQRT", "SUM1", "PROD1"
    };

    const QStringList ternaryOperators = {
        "SUM", "PROD"
    };

    bool isFound = false;
    if (unaryOperators.contains(token))
    // токен принадлежит токенам поддерживаемых операторов, составляющих унарную операцию
    {
        // токен является оператором выражения, операция – унарная
        isFound = true;
        *operandsCount = 1;
    }
    else if (binaryOperators.contains(token))
    //токен принадлежит токенам поддерживаемых операторов, составляющих бинарную операцию
    {
        // токен является оператором выражения, операция – бинарная
        isFound = true;
        *operandsCount = 2;
    }
    else if (ternaryOperators.contains(token))
    //токен принадлежит токенам поддерживаемых операторов, составляющих тернарную операцию
    {
        // токен является оператором выражения, операция – тернарная
        isFound = true;
        *operandsCount = 3;
    }
    return isFound;
}


QString fillOperationPatternWithParentheses(QString pattern, Operation* currentOp) {
    QString result;
    Operation* leftOp = nullptr;
    if (currentOp->getChildrenCount() == 1)
    // переданная операция является унарной
    {
        QString expression = currentOp->getChild(0)->toTex();
        // Заключить операнд в круглые скобки, если он представляет составное выражение (является операндом)
        // или текущая операция является корнем или модулем
        SqrtOperation* sqrtOp = dynamic_cast<SqrtOperation*>(currentOp);
        SqrtOperation* absOp = dynamic_cast<SqrtOperation*>(currentOp);
        SqrtOperation* rootOp = dynamic_cast<SqrtOperation*>(currentOp);

        bool isParenthesesAllowed = (sqrtOp == nullptr) && (absOp == nullptr) && (rootOp == nullptr);

        if (currentOp->getChild(0)->getChildrenCount() != 0 && isParenthesesAllowed) {
            expression = getExpressionWithParentheses(expression);
        }
        // Заполнить шаблон единственным операндом
        result = pattern.arg(expression);
    }
    else if (currentOp->getChildrenCount() == 2)
    // переданная операция является бинарной
    {
        QString leftExpression = currentOp->getChild(0)->toTex();
        QString rightExpression = currentOp->getChild(1)->toTex();

        Operation * leftOp = dynamic_cast<Operation*>(currentOp->getChild(0));
        Operation * rightOp = dynamic_cast<Operation*>(currentOp->getChild(1));

        bool isRightOperandParenthesesRequired = (dynamic_cast<SubOperation*>(currentOp) != nullptr) &&
                                                 dynamic_cast<SubOperation*>(currentOp->getChild(1));

        if (leftOp != nullptr) // левый операнд представляет собой составное выражение
        {
            if (leftOp->getPriority() < currentOp->getPriority() && leftOp->getPriority() != NO_PRIORITY)
            // текущая операция учитывает приоритет переданных операндов и
            // и левый операнд имеет приоритет ниже, чем приоритет текущей операции
            {
                // Заключить левый операнд в скобки
                leftExpression = getExpressionWithParentheses(leftExpression);
            }
        }
        if (rightOp != nullptr) // правый операнд представляет собой составное выражение
        {
            if ((rightOp->getPriority() < currentOp->getPriority() && rightOp->getPriority() != NO_PRIORITY)
                || isRightOperandParenthesesRequired)
            // текущая операция учитывает приоритет переданных операндов и
            // и правый операнд имеет приоритет ниже, чем приоритет текущей операции,
            // или текущая операция и правый операнд - вычитание
            {
                // Заключить правый операнд в скобки
                rightExpression = getExpressionWithParentheses(rightExpression);
            }
        }
        // Заполнить шаблон операции получившимися операндами
        result = pattern.arg(leftExpression, rightExpression);
    }
    else if (currentOp->getChildrenCount() == 3)
    // переданная операция является тернарной
    {
        result = pattern.arg(
            currentOp->getChild(0)->toTex(),
            currentOp->getChild(1)->toTex(),
            currentOp->getChild(2)->toTex());
    }
    return result;
}


QString getExpressionWithParentheses(QString expression) {
    // Добавить символ открывающей скобки к началу заданной строки выражения
    // и символ закрывающей скобки к концу заданной строки выражения
    //Считать полученную строку результатом преобразования
    return QString("(%1)").arg(expression);
}
