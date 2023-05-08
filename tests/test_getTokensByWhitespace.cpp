#include "test_getTokensByWhitespace.h"
#include "../functions.h"


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