#include "operators.h"

Operation* getOperation(QString token, QList<ExpressionTreeNode*> operands) {
    return nullptr;
}


bool isOperationToken(QString token, int * operandCount) {
    return false;
}

QString fillOperationPatternWithParentheses(QString pattern, Operation* currentOp) {
    return "";
}


QString getExpressionWithParentheses(QString expression) {
    // Добавить символ открывающей скобки к началу заданной строки выражения
    // и символ закрывающей скобки к концу заданной строки выражения
    //Считать полученную строку результатом преобразования
    return QString("(%1)").arg(expression);
}
