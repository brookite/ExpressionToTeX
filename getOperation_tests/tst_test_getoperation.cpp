
#include <QtTest>
#include "../ExpressionToTeX_main/operations.cpp"


void testExpressionTree(ExpressionTreeNode * real, ExpressionTreeNode * expected) {
    QCOMPARE(real->getChildrenCount(), expected->getChildrenCount());
    for (int i = 0; i < real->getChildrenCount(); i++) {
        testExpressionTree(real->getChild(i), expected->getChild(i));
    }
    if (real->getChildrenCount() == 0) {
        Value* realValue = dynamic_cast<Value*>(real);
        Value* expectedValue = dynamic_cast<Value*>(expected);

        QCOMPARE(realValue->getValue(), expectedValue->getValue());
        QCOMPARE(realValue->getType(), expectedValue->getType());
    }
    else {
        Operation* realOp = dynamic_cast<Operation*>(real);
        Operation* expectedOp = dynamic_cast<Operation*>(expected);

        QCOMPARE(realOp->getOperationToken(), expectedOp->getOperationToken());
    }
}

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

void Test_getOperation::plusOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    PlusOperation* expectedResult = new PlusOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("+", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::subOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    SubOperation* expectedResult = new SubOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("-", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}


void Test_getOperation::mulOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    MulOperation* expectedResult = new MulOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("*", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::divOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    DivOperation* expectedResult = new DivOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("/", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::lessOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    LessOperation* expectedResult = new LessOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("<", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::greaterOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    GreaterOperation* expectedResult = new GreaterOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation(">", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::lessOrEqualOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    LessEqualOperation* expectedResult = new LessEqualOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("<=", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::greaterOrEqualOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    GreaterEqualOperation* expectedResult = new GreaterEqualOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation(">=", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::notEqualOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    NotEqualOperation* expectedResult = new NotEqualOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("!=", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::logOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    LogOperation* expectedResult = new LogOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("LOG", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::powOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    PowOperation* expectedResult = new PowOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("^", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::subIndexOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    SubIndexOperation* expectedResult = new SubIndexOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("SUB", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::logicalAndOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    LogicalAndOperation* expectedResult = new LogicalAndOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("&", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::logicalOrOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    LogicalOrOperation* expectedResult = new LogicalOrOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("|", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::logicalXorOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    LogicalXorOperation* expectedResult = new LogicalXorOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("XOR", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::allQuantifierOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    AllQuantifierOperation* expectedResult = new AllQuantifierOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("FORALL", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::existQuantifierOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    ExistQuantifierOperation* expectedResult = new ExistQuantifierOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("EXISTS", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::modOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    ModOperation* expectedResult = new ModOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("%", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::rootOperation() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    RootOperation* expectedResult = new RootOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("ROOT", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::plusOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    PlusOperation* expectedResult = new PlusOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("+", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::subOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    SubOperation* expectedResult = new SubOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("-", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::mulOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    MulOperation* expectedResult = new MulOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("*", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::divOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    DivOperation* expectedResult = new DivOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("/", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::lessOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    LessOperation* expectedResult = new LessOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("<", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::greaterOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    GreaterOperation* expectedResult = new GreaterOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation(">", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::lessOrEqualOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    LessEqualOperation* expectedResult = new LessEqualOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("<=", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::greaterOrEqualOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    GreaterEqualOperation* expectedResult = new GreaterEqualOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation(">=", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::notEqualOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    NotEqualOperation* expectedResult = new NotEqualOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("!=", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::logOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    LogOperation* expectedResult = new LogOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("LOG", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::powOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    PowOperation* expectedResult = new PowOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("^", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::subIndexOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    SubIndexOperation* expectedResult = new SubIndexOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("SUB", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::logicalAndOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    LogicalAndOperation* expectedResult = new LogicalAndOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("&", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::logicalOrOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    LogicalOrOperation* expectedResult = new LogicalOrOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("|", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::logicalXorOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    LogicalXorOperation* expectedResult = new LogicalXorOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("XOR", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::allQuantifierOperationWithValues() {
    Value* rightOperand = new Value(IDENTIFIER, "x");
    Value* leftOperand = new Value(NUMERIC, "3");
    AllQuantifierOperation* expectedResult = new AllQuantifierOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("FORALL", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::existQuantifierOperationWithValues() {
    Value* rightOperand = new Value(IDENTIFIER, "x");
    Value* leftOperand = new Value(NUMERIC, "3");
    ExistQuantifierOperation* expectedResult = new ExistQuantifierOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("EXISTS", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::modOperationWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    ModOperation* expectedResult = new ModOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("%", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}


void Test_getOperation::unaryPlusOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    UnaryPlusOperation* expectedResult = new UnaryPlusOperation(operand);
    ExpressionTreeNode* realResult = getOperation("POS", { operand });

    testExpressionTree(realResult, expectedResult);

}

void Test_getOperation::unaryMinusOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    UnaryMinusOperation* expectedResult = new UnaryMinusOperation(operand);
    ExpressionTreeNode* realResult = getOperation("NEG", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::inversionOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    LogicalInversionOperation* expectedResult = new LogicalInversionOperation(operand);
    ExpressionTreeNode* realResult1 = getOperation("~", { operand });
    ExpressionTreeNode* realResult2 = getOperation("!", { operand });

    testExpressionTree(realResult1, expectedResult);
    testExpressionTree(realResult2, expectedResult);
}

void Test_getOperation::sinOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SinOperation* expectedResult = new SinOperation(operand);
    ExpressionTreeNode* realResult = getOperation("SIN", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::cosOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    CosOperation* expectedResult = new CosOperation(operand);
    ExpressionTreeNode* realResult = getOperation("COS", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::tanOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    TanOperation* expectedResult = new TanOperation(operand);
    ExpressionTreeNode* realResult = getOperation("TG", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::cotanOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    CotanOperation* expectedResult = new CotanOperation(operand);
    ExpressionTreeNode* realResult = getOperation("CTG", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::arcsinOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    ArcsinOperation* expectedResult = new ArcsinOperation(operand);
    ExpressionTreeNode* realResult = getOperation("ARCSIN", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::arccosOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    ArccosOperation* expectedResult = new ArccosOperation(operand);
    ExpressionTreeNode* realResult = getOperation("ARCCOS", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::arctanOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    ArctanOperation* expectedResult = new ArctanOperation(operand);
    ExpressionTreeNode* realResult = getOperation("ARCTG", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::arccotanOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    ArccotanOperation* expectedResult = new ArccotanOperation(operand);
    ExpressionTreeNode* realResult = getOperation("ARCCTG", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::absOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    AbsOperation* expectedResult = new AbsOperation(operand);
    ExpressionTreeNode* realResult = getOperation("ABS", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::lnOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    NaturalLogOperation* expectedResult = new NaturalLogOperation(operand);
    ExpressionTreeNode* realResult = getOperation("LN", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::lgOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    DecimalLogOperation* expectedResult = new DecimalLogOperation(operand);
    ExpressionTreeNode* realResult = getOperation("LG", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::sqrtOperation() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SqrtOperation* expectedResult = new SqrtOperation(operand);
    ExpressionTreeNode* realResult = getOperation("SQRT", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::unaryPlusOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    UnaryPlusOperation* expectedResult = new UnaryPlusOperation(operand);
    ExpressionTreeNode* realResult = getOperation("POS", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::unaryMinusOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    UnaryMinusOperation* expectedResult = new UnaryMinusOperation(operand);
    ExpressionTreeNode* realResult = getOperation("NEG", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::inversionOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    LogicalInversionOperation* expectedResult = new LogicalInversionOperation(operand);
    ExpressionTreeNode* realResult1 = getOperation("~", { operand });
    ExpressionTreeNode* realResult2 = getOperation("!", { operand });

    testExpressionTree(realResult1, expectedResult);
    testExpressionTree(realResult2, expectedResult);
}

void Test_getOperation::sinOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    SinOperation* expectedResult = new SinOperation(operand);
    ExpressionTreeNode* realResult = getOperation("SIN", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::cosOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    CosOperation* expectedResult = new CosOperation(operand);
    ExpressionTreeNode* realResult = getOperation("COS", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::tanOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    TanOperation* expectedResult = new TanOperation(operand);
    ExpressionTreeNode* realResult = getOperation("TG", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::cotanOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    CotanOperation* expectedResult = new CotanOperation(operand);
    ExpressionTreeNode* realResult = getOperation("CTG", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::arcsinOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    ArcsinOperation* expectedResult = new ArcsinOperation(operand);
    ExpressionTreeNode* realResult = getOperation("ARCSIN", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::arccosOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    ArccosOperation* expectedResult = new ArccosOperation(operand);
    ExpressionTreeNode* realResult = getOperation("ARCCOS", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::arctanOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    ArctanOperation* expectedResult = new ArctanOperation(operand);
    ExpressionTreeNode* realResult = getOperation("ARCTG", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::arccotanOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    ArccotanOperation* expectedResult = new ArccotanOperation(operand);
    ExpressionTreeNode* realResult = getOperation("ARCCTG", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::absOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    AbsOperation* expectedResult = new AbsOperation(operand);
    ExpressionTreeNode* realResult = getOperation("ABS", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::lnOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    NaturalLogOperation* expectedResult = new NaturalLogOperation(operand);
    ExpressionTreeNode* realResult = getOperation("LN", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::lgOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    DecimalLogOperation* expectedResult = new DecimalLogOperation(operand);
    ExpressionTreeNode* realResult = getOperation("LG", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::rootOperationWithValues() {
    Value* rightOperand = new Value(IDENTIFIER, "x");
    Value* leftOperand = new Value(NUMERIC, "3");
    RootOperation* expectedResult = new RootOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("ROOT", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::sqrtOperationWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    SqrtOperation* expectedResult = new SqrtOperation(operand);
    ExpressionTreeNode* realResult = getOperation("SQRT", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::sumOperation() {
    EqualOperation* firstOperand = new EqualOperation(
        new Value(IDENTIFIER, "i"),
        new Value(NUMERIC, "1")
        );
    Value* secondOperand = new Value(IDENTIFIER, "n");
    PlusOperation* thirdOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    SumOperation* expectedResult = new SumOperation(firstOperand, secondOperand, thirdOperand);
    ExpressionTreeNode* realResult = getOperation("SUM", { firstOperand, secondOperand, thirdOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::prodOperation() {
    EqualOperation* firstOperand = new EqualOperation(
        new Value(IDENTIFIER, "i"),
        new Value(NUMERIC, "1")
        );
    Value* secondOperand = new Value(IDENTIFIER, "n");
    PlusOperation* thirdOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ProdOperation* expectedResult = new ProdOperation(firstOperand, secondOperand, thirdOperand);
    ExpressionTreeNode* realResult = getOperation("PROD", { firstOperand, secondOperand, thirdOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::sumOperationWithoutEndInterval() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    SumOperation* expectedResult = new SumOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("SUM2", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::prodOperationWithoutEndInterval() {
    PlusOperation* leftOperand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SubOperation* rightOperand = new SubOperation(
        new Value(IDENTIFIER, "y"),
        new Value(NUMERIC, "2")
        );

    ProdOperation* expectedResult = new ProdOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("PROD2", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::sumOperationWithoutIntervals() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    SumOperation* expectedResult = new SumOperation(operand);
    ExpressionTreeNode* realResult = getOperation("SUM1", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::prodOperationWithoutIntervals() {
    PlusOperation* operand = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    ProdOperation* expectedResult = new ProdOperation(operand);
    ExpressionTreeNode* realResult = getOperation("PROD1", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::sumOperationWithoutEndIntervalWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    SumOperation* expectedResult = new SumOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("SUM2", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::prodOperationWithoutEndIntervalWithValues() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");
    ProdOperation* expectedResult = new ProdOperation(leftOperand, rightOperand);
    ExpressionTreeNode* realResult = getOperation("PROD2", { leftOperand, rightOperand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::sumOperationWithoutIntervalsWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    SumOperation* expectedResult = new SumOperation(operand);
    ExpressionTreeNode* realResult = getOperation("SUM1", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::prodOperationWithoutIntervalsWithValues() {
    Value* operand = new Value(NUMERIC, "4");

    ProdOperation* expectedResult = new ProdOperation(operand);
    ExpressionTreeNode* realResult = getOperation("PROD1", { operand });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::unknownBinaryOperation() {
    Value* leftOperand = new Value(IDENTIFIER, "x");
    Value* rightOperand = new Value(NUMERIC, "3");

    ExpressionTreeNode* realResult = getOperation("PLUS", { leftOperand, rightOperand });

    QVERIFY2(realResult == nullptr, "Unknown token has not-null operation");
}

void Test_getOperation::unknownUnaryOperation() {
    Value* operand = new Value(NUMERIC, "4");
    ExpressionTreeNode* realResult = getOperation("SUMMA", { operand });

    QVERIFY2(realResult == nullptr, "Unknown token has not-null operation");
}

void Test_getOperation::leftOperandIsOperation() {
    PlusOperation* operand1 = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    Value * operand2 = new Value(NUMERIC, "2");

    MulOperation* expectedResult = new MulOperation(operand1, operand2);
    ExpressionTreeNode* realResult = getOperation("*", { operand1, operand2 });

    testExpressionTree(realResult, expectedResult);
}

void Test_getOperation::rightOperandIsOperation() {
    PlusOperation* operand1 = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );
    Value* operand2 = new Value(NUMERIC, "2");

    MulOperation* expectedResult = new MulOperation(operand2, operand1);
    ExpressionTreeNode* realResult = getOperation("*", { operand2, operand1 });

    testExpressionTree(realResult, expectedResult);
}
QTEST_APPLESS_MAIN(Test_getOperation)

#include "tst_test_getoperation.moc"
