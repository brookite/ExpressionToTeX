
#include <QtTest>
#include "../ExpressionToTeX_main/expressions.h"


class Test_recognizeValueToken : public QObject
{
    Q_OBJECT
private slots:
    void integerValue();
    void floatValue();
    void variableValue();
    void longVariableValue();
    void variableWithOnlyCaptialLetterValue();
    void variableWithCaptialLetterValue();
    void negativeIntegerValue();
    void negativeFloatValue();
    void zeroFloatValue();
    void zeroIntegerValue();
};

void testEqualValueToken(Value * real, Value* expected) {
    if (real == nullptr) {
        QFAIL("Value token recognition has failed");
    }
    else {
        QCOMPARE(real->getType(), expected->getType());
        QCOMPARE(real->getValue(), expected->getValue());
    }
}


void Test_recognizeValueToken::integerValue() {
    QString inputToken = "145";
    Value expectedResult(NUMERIC, inputToken);
    Value* realResult = recognizeValueToken(inputToken);

    testEqualValueToken(realResult, &expectedResult);
}

void Test_recognizeValueToken::floatValue() {
    QString inputToken = "15.3";
    Value expectedResult(NUMERIC, inputToken);
    Value* realResult = recognizeValueToken(inputToken);

    testEqualValueToken(realResult, &expectedResult);
}

void Test_recognizeValueToken::variableValue() {
    QString inputToken = "x";
    Value expectedResult(IDENTIFIER, inputToken);
    Value* realResult = recognizeValueToken(inputToken);

    testEqualValueToken(realResult, &expectedResult);
}

void Test_recognizeValueToken::longVariableValue() {
    QString inputToken = "var";
    Value expectedResult(IDENTIFIER, inputToken);
    Value* realResult = recognizeValueToken(inputToken);

    testEqualValueToken(realResult, &expectedResult);
}

void Test_recognizeValueToken::variableWithOnlyCaptialLetterValue() {
    QString inputToken = "X";
    Value expectedResult(IDENTIFIER, inputToken);
    Value* realResult = recognizeValueToken(inputToken);

    testEqualValueToken(realResult, &expectedResult);
}

void Test_recognizeValueToken::variableWithCaptialLetterValue() {
    QString inputToken = "Xz";
    Value expectedResult(IDENTIFIER, inputToken);
    Value* realResult = recognizeValueToken(inputToken);

    testEqualValueToken(realResult, &expectedResult);
}

void Test_recognizeValueToken::negativeIntegerValue() {
    QString inputToken = "-34";
    Value expectedResult(NUMERIC, inputToken);
    Value* realResult = recognizeValueToken(inputToken);

    testEqualValueToken(realResult, &expectedResult);
}

void Test_recognizeValueToken::negativeFloatValue() {
    QString inputToken = "-1.86";
    Value expectedResult(NUMERIC, inputToken);
    Value* realResult = recognizeValueToken(inputToken);

    testEqualValueToken(realResult, &expectedResult);
}

void Test_recognizeValueToken::zeroFloatValue() {
    QString inputToken = "0.00";
    Value expectedResult(NUMERIC, inputToken);
    Value* realResult = recognizeValueToken(inputToken);

    testEqualValueToken(realResult, &expectedResult);
}

void Test_recognizeValueToken::zeroIntegerValue() {
    QString inputToken = "0";
    Value expectedResult(NUMERIC, inputToken);
    Value* realResult = recognizeValueToken(inputToken);

    testEqualValueToken(realResult, &expectedResult);
}

QTEST_APPLESS_MAIN(Test_recognizeValueToken)

#include "tst_test_recognizevaluetoken.moc"
