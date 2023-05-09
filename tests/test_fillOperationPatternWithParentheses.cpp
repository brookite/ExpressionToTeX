#include "Test_fillOperationPatternWithParentheses.h"
#include "../expressions.h"
#include "../operations.cpp"


void Test_fillOperationPatternWithParentheses::priorityIsNotRequired() {
	Value x(IDENTIFIER, "x");
	Value y(IDENTIFIER, "y");

	PlusOperation * inputOperation = new PlusOperation(&x, &y);
	QString pattern = "%1 + %2";
	QString expectedResult = "x + y";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}

void Test_fillOperationPatternWithParentheses::leftOperandHasHigherPriority() {
	Value x(IDENTIFIER, "x");
	Value number1(NUMERIC, "3");
	Value number2(NUMERIC, "2");

	MulOperation * mulOp = new MulOperation(&x, &number1);
	PlusOperation * inputOperation = new PlusOperation(mulOp, &number2);

	QString pattern = "%1 + %2";
	QString expectedResult = "3x + 2";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}

void Test_fillOperationPatternWithParentheses::rightOperandHasHigherPriority() {
	Value x(IDENTIFIER, "x");
	Value number1(NUMERIC, "3");
	Value number2(NUMERIC, "2");

	MulOperation * mulOp = new MulOperation(&x, &number1);
	PlusOperation * inputOperation = new PlusOperation(&number2, mulOp);

	QString pattern = "%1 + %2";
	QString expectedResult = "2 + 3x";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}

void Test_fillOperationPatternWithParentheses::leftOperandHasSamePriority() {
	Value x(IDENTIFIER, "x");
	Value number1(NUMERIC, "3");
	Value number2(NUMERIC, "2");

	SubOperation * subOp = new SubOperation(&x, &number1);
	PlusOperation * inputOperation = new PlusOperation(subOp, &number2);

	QString pattern = "%1 + %2";
	QString expectedResult = "x - 3 + 2";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}

void Test_fillOperationPatternWithParentheses::rightOperandHasSamePriority() {
	Value x(IDENTIFIER, "x");
	Value number1(NUMERIC, "3");
	Value number2(NUMERIC, "2");

	SubOperation * subOp = new SubOperation(&x, &number1);
	PlusOperation * inputOperation = new PlusOperation(&number2, subOp);

	QString pattern = "%1 + %2";
	QString expectedResult = "2 + x - 3";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}


void Test_fillOperationPatternWithParentheses::leftOperandHasLowerPriority() {
	Value x(IDENTIFIER, "x");
	Value number1(NUMERIC, "3");
	Value number2(NUMERIC, "2");

	PlusOperation * plusOp = new PlusOperation(&x, &number1);
	MulOperation * inputOperation = new MulOperation(plusOp, &number2);

	QString pattern = "%1 \\cdot %2";
	QString expectedResult = "(x + 3) \\cdot 2";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}

void Test_fillOperationPatternWithParentheses::rightOperandHasLowerPriority() {
	Value x(IDENTIFIER, "x");
	Value number1(NUMERIC, "3");
	Value number2(NUMERIC, "2");

	PlusOperation * plusOp = new PlusOperation(&x, &number1);
	MulOperation * inputOperation = new MulOperation(&number2, plusOp);

	QString pattern = "%1 \\cdot %2";
	QString expectedResult = "2 \\cdot (x + 3)";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}

void Test_fillOperationPatternWithParentheses::leftOperandWithNoPriority() {
	Value x(IDENTIFIER, "x");
	Value number1(NUMERIC, "3");
	Value number2(NUMERIC, "2");

	SubIndexOperation * subindexOp = new SubIndexOperation(&x, &number1);
	MulOperation * inputOperation = new MulOperation(subindexOp, &number2);

	QString pattern = "%1 \\cdot %2";
	QString expectedResult = "{x}_{3} \\cdot 2";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}

void Test_fillOperationPatternWithParentheses::rightOperandWithNoPriority() {
	Value x(IDENTIFIER, "x");
	Value number1(NUMERIC, "3");
	Value number2(NUMERIC, "2");

	SubIndexOperation * subindexOp = new SubIndexOperation(&x, &number1);
	MulOperation * inputOperation = new MulOperation(&number2, subindexOp);

	QString pattern = "%1 \\cdot %2";
	QString expectedResult = "2 \\cdot {x}_{3}";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}

void Test_fillOperationPatternWithParentheses::allOperandsWithNoPriority() {
	Value x(IDENTIFIER, "x");
	Value number1(NUMERIC, "1");
	Value number2(NUMERIC, "3");

	SubIndexOperation * subindexOp1 = new SubIndexOperation(&x, &number1);
	SubIndexOperation * subindexOp2 = new SubIndexOperation(&x, &number2);
	MulOperation * inputOperation = new MulOperation(subindexOp1, subindexOp2);

	QString pattern = "%1 \\cdot %2";
	QString expectedResult = "{x}_{1} \\cdot {x}_{3}";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}

void Test_fillOperationPatternWithParentheses::allOperandsWithHigherPriority() {
	Value x(IDENTIFIER, "x");
	Value number1(NUMERIC, "2");
	Value number2(NUMERIC, "3");

	MulOperation * mulOp1 = new MulOperation(&x, &number1);
	MulOperation * mulOp2 = new MulOperation(&x, &number2);
	PlusOperation * inputOperation = new PlusOperation(mulOp1, mulOp2);

	QString pattern = "%1 + %2";
	QString expectedResult = "2x + 3x";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}


void Test_fillOperationPatternWithParentheses::allOperandsWithLowerPriority() {
	Value x(IDENTIFIER, "x");
	Value number1(NUMERIC, "2");
	Value number2(NUMERIC, "3");

	PlusOperation * plusOp1 = new PlusOperation(&x, &number1);
	PlusOperation * plusOp2 = new PlusOperation(&x, &number2);
	MulOperation * inputOperation = new MulOperation(plusOp1, plusOp2);

	QString pattern = "%1 \\cdot %2";
	QString expectedResult = "(x + 2) \\cdot (x + 3)";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}


void Test_fillOperationPatternWithParentheses::allOperandsWithSamePriority() {
	Value x(IDENTIFIER, "x");
	Value number1(NUMERIC, "2");
	Value number2(NUMERIC, "3");

	SubOperation * subOp1 = new SubOperation(&x, &number1);
	SubOperation * subOp2 = new SubOperation(&x, &number2);
	PlusOperation * inputOperation = new PlusOperation(subOp1, subOp2);

	QString pattern = "%1 + %2";
	QString expectedResult = "x - 2 + x - 3";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}

void Test_fillOperationPatternWithParentheses::unaryOperationWithComplexOperand() {
	Value x(IDENTIFIER, "x");
	Value number(NUMERIC, "2");

	PowOperation* powOp = new PowOperation(&x, &number);
	SinOperation* inputOperation = new SinOperation(powOp);

	QString pattern = "\\sin{%1}";
	QString expectedResult = "\\sin{({x}^{2})}";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}

void Test_fillOperationPatternWithParentheses::unaryOperationWithValue() {
	Value x(IDENTIFIER, "x");
	SinOperation* inputOperation = new SinOperation(&x);

	QString pattern = "\\sin{%1}";
	QString expectedResult = "\\sin{x}";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}

void Test_fillOperationPatternWithParentheses::unaryOperationWithComplexOperandWithoutParentheses() {
	Value x(IDENTIFIER, "x");
	Value number(NUMERIC, "2");

	PowOperation* powOp = new PowOperation(&x, &number);
	SqrtOperation* inputOperation = new SqrtOperation(powOp);

	QString pattern = "\\sqrt{%1}";
	QString expectedResult = "\\sqrt{{x}^{2}}";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}

void Test_fillOperationPatternWithParentheses::currentOperationIsSubtractionLeftOpIsSubtraction() {
	Value x(IDENTIFIER, "x");
	Value number1(NUMERIC, "2");
	Value number2(NUMERIC, "3");

	SubOperation* subOp = new SubOperation(&x, &number2);
	SubOperation* inputOperation = new SubOperation(subOp, &number1);

	QString pattern = "%1 - %2";
	QString expectedResult = "x - 3 - 2";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}

void Test_fillOperationPatternWithParentheses::currentOperationIsSubtractionRightOpIsSubtraction() {
	Value x(IDENTIFIER, "x");
	Value number1(NUMERIC, "2");
	Value number2(NUMERIC, "3");

	SubOperation* subOp = new SubOperation(&x, &number2);
	SubOperation* inputOperation = new SubOperation(&number1, subOp);

	QString pattern = "%1 - %2";
	QString expectedResult = "2 - (x - 3)";
	QString realResult = fillOperationPatternWithParentheses(pattern, inputOperation);

	QCOMPARE(realResult, expectedResult);
}
