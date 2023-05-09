#pragma once
#include <QTest>
#include <QObject>


class Test_fillOperationPatternWithParentheses : public QObject
{
    Q_OBJECT
private slots:
    void priorityIsNotRequired();

    void leftOperandHasHigherPriority();

    void rightOperandHasHigherPriority();

    void leftOperandHasSamePriority();

    void rightOperandHasSamePriority();

    void leftOperandHasLowerPriority();

    void rightOperandHasLowerPriority();

    void leftOperandWithNoPriority();

    void rightOperandWithNoPriority();

    void allOperandsWithNoPriority();

    void allOperandsWithHigherPriority();

    void allOperandsWithLowerPriority();

    void allOperandsWithSamePriority();

    void unaryOperationWithComplexOperand();

    void unaryOperationWithValue();

    void unaryOperationWithComplexOperandWithoutParentheses();

    void currentOperationIsSubtractionLeftOpIsSubtraction();

    void currentOperationIsSubtractionRightOpIsSubtraction();

};
