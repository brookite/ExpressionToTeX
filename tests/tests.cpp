#include "tests.h"


void runTests() {
	QTest::qExec(new Test_getTokensByWhitespace);
	QTest::qExec(new Test_recognizeValueToken);
	QTest::qExec(new Test_getExpressionWithParentheses);
	QTest::qExec(new Test_isOperationToken);
	QTest::qExec(new Test_getOperation);
	QTest::qExec(new Test_buildExpressionTree);
	QTest::qExec(new Test_postfixExpressionToTex);
	QTest::qExec(new Test_fillOperationPatternWithParentheses);
}