
#include <QtTest>
#include "../ExpressionToTeX_main/operators.h"


class Test_getExpressionWithParentheses : public QObject
{
    Q_OBJECT
private slots:
    void stringWithCharacters();
    void emptyString();
    void singleCharacterString();
    void stringAlreadyInParentheses();
};


void Test_getExpressionWithParentheses::stringWithCharacters() {
    QString inputExpression = "string";
    QString expectedResult = "(string)";
    QString realResult = getExpressionWithParentheses(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getExpressionWithParentheses::emptyString() {
    QString inputExpression = "";
    QString expectedResult = "()";
    QString realResult = getExpressionWithParentheses(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getExpressionWithParentheses::singleCharacterString() {
    QString inputExpression = "a";
    QString expectedResult = "(a)";
    QString realResult = getExpressionWithParentheses(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getExpressionWithParentheses::stringAlreadyInParentheses() {
    QString inputExpression = "(string)";
    QString expectedResult = "((string))";
    QString realResult = getExpressionWithParentheses(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

QTEST_APPLESS_MAIN(Test_getExpressionWithParentheses)

#include "tst_test_getexpressionwithparentheses.moc"
