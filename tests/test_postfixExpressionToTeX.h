#pragma once

#include <QTest>
#include <QObject>


class Test_postfixExpressionToTex : public QObject
{
    Q_OBJECT
private slots:
    void fewOperationsWithoutParentheses();
    void fewOperationsWithLeftOperandInParentheses();
    void fewOperationsWithRightOperandInParentheses();
    void fewOperationsWithAllOperandsInParentheses();
    void tabSeparator();
    void variablesInExpression();
    void longVariablesInExpression();
    void multiplyNumberAndVariableExpression();
    void multiplyVariableAndNumberExpression();
    void onlyFloatNumbersInExpression();
    void plusOperation();
    void subOperation();
    void mulOperation();
    void divOperation();
    void lessOperation();
    void greaterOperation();
    void lessOrEqualOperation();
    void greaterOrEqualOperation();
    void notEqualOperation();
    void logOperation();
    void powOperation();
    void subIndexOperation();
    void logicalAndOperation();
    void logicalOrOperation();
    void logicalXorOperation();
    void allQuantifierOperation();
    void existQuantifierOperation();
    void modOperation();
    void unaryPlusOperation();
    void unaryMinusOperation();
    void inversionOperation();
    void sinOperation();
    void cosOperation();
    void tanOperation();
    void cotanOperation();
    void arcsinOperation();
    void arccosOperation();
    void arctanOperation();
    void arccotanOperation();
    void absOperation();
    void lnOperation();
    void lgOperation();
    void rootOperation();
    void sqrtOperation();
    void sumOperation();
    void prodOperation();
    void sumOperationWithoutEndInterval();
    void prodOperationWithoutEndInterval();
    void sumOperationWithoutIntervals();
    void prodOperationWithoutIntervals();
    void integerValueInExpression();
    void floatValueInExpression();
    void variableInExpression();
    void longVariableInExpression();
    void complexTest1();
    void complexTest2();
};

