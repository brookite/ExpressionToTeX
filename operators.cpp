#include <QStringList>
#include <QRegularExpression>
#include "operations.cpp"


Operation* getOperation(QString token, QList<ExpressionTreeNode*> operands) {
    return nullptr;
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
