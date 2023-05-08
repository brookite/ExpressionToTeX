#include "test_getExpressionWithParentheses.h"
#include "../operators.h"

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