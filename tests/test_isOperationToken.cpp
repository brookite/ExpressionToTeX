#include "Test_isOperationToken.h"
#include "../operators.h"


void Test_isOperationToken::plusOperation() {
	QString token = "+";
	
	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}


void Test_isOperationToken::subOperation() {
	QString token = "-";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}


void Test_isOperationToken::mulOperation() {
	QString token = "*";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::divOperation() {
	QString token = "/";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::lessOperation() {
	QString token = "<";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::greaterOperation() {
	QString token = ">";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::lessOrEqualOperation() {
	QString token = "<=";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::greaterOrEqualOperation() {
	QString token = ">=";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::notEqualOperation() {
	QString token = "!=";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::logOperation() {
	QString token = "LOG";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::powOperation() {
	QString token = "^";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::subIndexOperation() {
	QString token = "SUB";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::logicalAndOperation() {
	QString token = "&";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::logicalOrOperation() {
	QString token = "|";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::logicalXorOperation() {
	QString token = "XOR";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::allQuantifierOperation() {
	QString token = "FORALL";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::existQuantifierOperation() {
	QString token = "EXISTS";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::modOperation() {
	QString token = "%";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::unaryPlusOperation() {
	QString token = "POS";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::unaryMinusOperation() {
	QString token = "NEG";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::inversionOperation() {
	QString token1 = "!";
	QString token2 = "~";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token1, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);

	realResult = isOperationToken(token2, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::sinOperation() {
	QString token = "SIN";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}


void Test_isOperationToken::cosOperation() {
	QString token = "COS";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}


void Test_isOperationToken::tanOperation() {
	QString token = "TG";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}


void Test_isOperationToken::cotanOperation() {
	QString token = "CTG";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::arcsinOperation() {
	QString token = "ARCSIN";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}


void Test_isOperationToken::arccosOperation() {
	QString token = "ARCCOS";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}


void Test_isOperationToken::arctanOperation() {
	QString token = "ARCTG";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}


void Test_isOperationToken::arccotanOperation() {
	QString token = "ARCCTG";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::absOperation() {
	QString token = "ABS";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::lnOperation() {
	QString token = "LN";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::lgOperation() {
	QString token = "LG";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::rootOperation() {
	QString token = "ROOT";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::sqrtOperation() {
	QString token = "SQRT";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::sumOperation() {
	QString token = "SUM";

	int expectedArgumentCount = 3;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::prodOperation() {
	QString token = "PROD";

	int expectedArgumentCount = 3;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::sumOperationWithoutEndInterval() {
	QString token = "SUM2";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::prodOperationWithoutEndInterval() {
	QString token = "PROD2";

	int expectedArgumentCount = 2;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::sumOperationWithoutIntervals() {
	QString token = "SUM1";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::prodOperationWithoutIntervals() {
	QString token = "PROD1";

	int expectedArgumentCount = 1;
	bool expectedResult = true;

	int realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}

void Test_isOperationToken::invalidToken() {
	QString token = "PLUS";

	bool expectedResult = false;
	int realArgumentCount;
	int expectedArgumentCount = realArgumentCount;
	bool realResult = isOperationToken(token, &realArgumentCount);

	QCOMPARE(realResult, expectedResult);
	QCOMPARE(realArgumentCount, expectedArgumentCount);
}