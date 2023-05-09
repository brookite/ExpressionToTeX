#pragma once
#include <QTest>
#include <QObject>


class Test_getOperation : public QObject
{
    Q_OBJECT
private slots:
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

    void plusOperationWithValues();
    void subOperationWithValues();
    void mulOperationWithValues();
    void divOperationWithValues();
    void lessOperationWithValues();
    void greaterOperationWithValues();
    void lessOrEqualOperationWithValues();
    void greaterOrEqualOperationWithValues();
    void notEqualOperationWithValues();
    void logOperationWithValues();
    void powOperationWithValues();
    void subIndexOperationWithValues();
    void logicalAndOperationWithValues();
    void logicalOrOperationWithValues();
    void logicalXorOperationWithValues();
    void allQuantifierOperationWithValues();
    void existQuantifierOperationWithValues();
    void modOperationWithValues();


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

    void unaryPlusOperationWithValues();
    void unaryMinusOperationWithValues();
    void inversionOperationWithValues();
    void sinOperationWithValues();
    void cosOperationWithValues();
    void tanOperationWithValues();
    void cotanOperationWithValues();
    void arcsinOperationWithValues();
    void arccosOperationWithValues();
    void arctanOperationWithValues();
    void arccotanOperationWithValues();
    void absOperationWithValues();
    void lnOperationWithValues();
    void lgOperationWithValues();
    void rootOperationWithValues();
    void sqrtOperationWithValues();

    void sumOperation();
    void prodOperation();
    void sumOperationWithoutEndInterval();
    void prodOperationWithoutEndInterval();
    void sumOperationWithoutIntervals();
    void prodOperationWithoutIntervals();

    void sumOperationWithoutEndIntervalWithValues();
    void prodOperationWithoutEndIntervalWithValues();
    void sumOperationWithoutIntervalsWithValues();
    void prodOperationWithoutIntervalsWithValues();
    void unknownBinaryOperation();
    void unknownUnaryOperation();
    void leftOperandIsOperation();
    void rightOperandIsOperation();
};
