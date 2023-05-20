
#include <QtTest>
#include "../ExpressionToTeX_main/functions.h"


class Test_getTokensByWhitespace : public QObject
{
    Q_OBJECT
private slots:
    void tokensSeparatedByWhitespace();
    void onlyOneToken();
    void noTokens();
    void tokensSeparatedByTab();
    void oneOfTokenHasLengthGreaterThan1();
    void manyOfTokensHasLengthGreaterThan1();
    void allOfTokensHasLengthGreaterThan1();
    void manyOfTokensHasLengthGreaterThan1SeparatedByTab();
    void tokensSeparatedByWhitespaceAndTabs();
    void expresstionStartsWithWhitespaces();
    void expresstionStartsWithWhitespace();
    void expresstionEndsWithWhitespaces();
    void expresstionEndsWithWhitespace();
};



void Test_getTokensByWhitespace::tokensSeparatedByWhitespace() {
    QString inputExpression = "4 3 + 5 *";
    QStringList expectedResult = { "4", "3", "+", "5", "*" };
    QStringList realResult = getTokensByWhitespace(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getTokensByWhitespace::onlyOneToken() {
    QString inputExpression = "+";
    QStringList expectedResult = { "+" };
    QStringList realResult = getTokensByWhitespace(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getTokensByWhitespace::noTokens() {
    QString inputExpression = "";
    QStringList expectedResult = { };
    QStringList realResult = getTokensByWhitespace(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getTokensByWhitespace::tokensSeparatedByTab() {
    QString inputExpression = "4\t3\t+\t5\t*";
    QStringList expectedResult = { "4", "3", "+", "5", "*" };
    QStringList realResult = getTokensByWhitespace(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getTokensByWhitespace::oneOfTokenHasLengthGreaterThan1() {
    QString inputExpression = "4 3 + var *";
    QStringList expectedResult = { "4", "3", "+", "var", "*" };
    QStringList realResult = getTokensByWhitespace(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getTokensByWhitespace::manyOfTokensHasLengthGreaterThan1() {
    QString inputExpression = "4 var3 + var *";
    QStringList expectedResult = { "4", "var3", "+", "var", "*" };
    QStringList realResult = getTokensByWhitespace(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getTokensByWhitespace::allOfTokensHasLengthGreaterThan1() {
    QString inputExpression = "var1 var2 var3 var4 var5";
    QStringList expectedResult = { "var1", "var2", "var3", "var4", "var5" };
    QStringList realResult = getTokensByWhitespace(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getTokensByWhitespace::manyOfTokensHasLengthGreaterThan1SeparatedByTab() {
    QString inputExpression = "var1\tvar2\tvar3\tvar4\tvar5";
    QStringList expectedResult = { "var1", "var2", "var3", "var4", "var5" };
    QStringList realResult = getTokensByWhitespace(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getTokensByWhitespace::tokensSeparatedByWhitespaceAndTabs() {
    QString inputExpression = "4 3\t+ 5\t*";
    QStringList expectedResult = { "4", "3", "+", "5", "*" };
    QStringList realResult = getTokensByWhitespace(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getTokensByWhitespace::expresstionStartsWithWhitespaces() {
    QString inputExpression = "    4 3 + 5 *";
    QStringList expectedResult = { "4", "3", "+", "5", "*" };
    QStringList realResult = getTokensByWhitespace(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getTokensByWhitespace::expresstionStartsWithWhitespace() {
    QString inputExpression = " 4 3 + 5 *";
    QStringList expectedResult = { "4", "3", "+", "5", "*" };
    QStringList realResult = getTokensByWhitespace(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getTokensByWhitespace::expresstionEndsWithWhitespaces() {
    QString inputExpression = "4 3 + 5 *    ";
    QStringList expectedResult = { "4", "3", "+", "5", "*" };
    QStringList realResult = getTokensByWhitespace(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_getTokensByWhitespace::expresstionEndsWithWhitespace() {
    QString inputExpression = "4 3 + 5 * ";
    QStringList expectedResult = { "4", "3", "+", "5", "*" };
    QStringList realResult = getTokensByWhitespace(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

QTEST_APPLESS_MAIN(Test_getTokensByWhitespace)

#include "tst_test_gettokensbywhitespace.moc"
