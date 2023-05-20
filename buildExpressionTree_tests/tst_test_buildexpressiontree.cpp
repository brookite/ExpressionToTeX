
#include <QtTest>
#include "../ExpressionToTeX_main/operations.cpp"
#include "../ExpressionToTeX_main/exceptions.h"


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


class Test_buildExpressionTree : public QObject
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
    void sumOperation();
    void prodOperation();
    void operationHasNotEnoughArguments();
    void operationHasInvalidValue();
    void operationHasInvalidVariable();
    void emptyTokens();
    void leftOperandIsOperation();
    void rightOperandIsOperation();
    void allOperandsAreOperations();
};

void Test_buildExpressionTree::plusOperation() {
    QStringList list = { "x", "3", "+" };

    PlusOperation * expectedResult = new PlusOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}


void Test_buildExpressionTree::subOperation() {
    QStringList list = { "x", "3", "-" };

    SubOperation* expectedResult = new SubOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}


void Test_buildExpressionTree::mulOperation() {
    QStringList list = { "x", "3", "*" };

    MulOperation* expectedResult = new MulOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::divOperation() {
    QStringList list = { "x", "3", "/" };

    DivOperation* expectedResult = new DivOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::lessOperation() {
    QStringList list = { "x", "3", "<" };

    LessOperation* expectedResult = new LessOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::greaterOperation() {
    QStringList list = { "x", "3", ">" };

    GreaterOperation* expectedResult = new GreaterOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::lessOrEqualOperation() {
    QStringList list = { "x", "3", "<=" };

    LessEqualOperation* expectedResult = new LessEqualOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::greaterOrEqualOperation() {
    QStringList list = { "x", "3", ">=" };

    GreaterEqualOperation* expectedResult = new GreaterEqualOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::notEqualOperation() {
    QStringList list = { "x", "3", "!=" };

    NotEqualOperation* expectedResult = new NotEqualOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::logOperation() {
    QStringList list = { "3", "x", "LOG" };

    LogOperation* expectedResult = new LogOperation(
        new Value(NUMERIC, "3"),
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::powOperation() {
    QStringList list = { "x", "3", "^" };

    PowOperation* expectedResult = new PowOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::subIndexOperation() {
    QStringList list = { "x", "3", "SUB" };

    SubIndexOperation* expectedResult = new SubIndexOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::logicalAndOperation() {
    QStringList list = { "x", "3", "&" };

    LogicalAndOperation* expectedResult = new LogicalAndOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::logicalOrOperation() {
    QStringList list = { "x", "3", "|" };

    LogicalOrOperation* expectedResult = new LogicalOrOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::logicalXorOperation() {
    QStringList list = { "x", "3", "XOR" };

    LogicalXorOperation* expectedResult = new LogicalXorOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::allQuantifierOperation() {
    QStringList list = { "x", "x", "3" ,"<", "FORALL" };

    AllQuantifierOperation* expectedResult = new AllQuantifierOperation(
        new Value(IDENTIFIER, "x"),
        new LessOperation(
            new Value(IDENTIFIER, "x"),
            new Value(NUMERIC, "3")
            )
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::existQuantifierOperation() {
    QStringList list = { "x", "x", "3", ">", "EXISTS" };

    ExistQuantifierOperation* expectedResult = new ExistQuantifierOperation(
        new Value(IDENTIFIER, "x"),
        new GreaterOperation(
            new Value(IDENTIFIER, "x"),
            new Value(NUMERIC, "3")
            )
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::modOperation() {
    QStringList list = { "x", "3", "%" };

    ModOperation* expectedResult = new ModOperation(
        new Value(IDENTIFIER, "x"),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::unaryPlusOperation() {
    QStringList list = { "x", "POS" };

    UnaryPlusOperation* expectedResult = new UnaryPlusOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::unaryMinusOperation() {
    QStringList list = { "x", "NEG" };

    UnaryMinusOperation* expectedResult = new UnaryMinusOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::inversionOperation() {
    QStringList list = { "x", "~" };

    LogicalInversionOperation* expectedResult = new LogicalInversionOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::sinOperation() {
    QStringList list = { "x", "SIN" };

    SinOperation* expectedResult = new SinOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}


void Test_buildExpressionTree::cosOperation() {
    QStringList list = { "x", "COS" };

    CosOperation* expectedResult = new CosOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}


void Test_buildExpressionTree::tanOperation() {
    QStringList list = { "x", "TG" };

    TanOperation* expectedResult = new TanOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}


void Test_buildExpressionTree::cotanOperation() {
    QStringList list = { "x", "CTG" };

    CotanOperation* expectedResult = new CotanOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::arcsinOperation() {
    QStringList list = { "x", "ARCSIN" };

    ArcsinOperation* expectedResult = new ArcsinOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}


void Test_buildExpressionTree::arccosOperation() {
    QStringList list = { "x", "ARCCOS" };

    ArccosOperation* expectedResult = new ArccosOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}


void Test_buildExpressionTree::arctanOperation() {
    QStringList list = { "x", "ARCTG" };

    ArctanOperation* expectedResult = new ArctanOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}


void Test_buildExpressionTree::arccotanOperation() {
    QStringList list = { "x", "ARCCTG" };

    ArccotanOperation* expectedResult = new ArccotanOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::absOperation() {
    QStringList list = { "x", "ABS" };

    AbsOperation* expectedResult = new AbsOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::lnOperation() {
    QStringList list = { "x", "LN" };

    NaturalLogOperation* expectedResult = new NaturalLogOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::lgOperation() {
    QStringList list = { "x", "LG" };

    DecimalLogOperation* expectedResult = new DecimalLogOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::rootOperation() {
    QStringList list = { "3", "x", "ROOT" };

    RootOperation* expectedResult = new RootOperation(
        new Value(NUMERIC, "3"),
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::sqrtOperation() {
    QStringList list = { "x", "SQRT" };

    SqrtOperation* expectedResult = new SqrtOperation(
        new Value(IDENTIFIER, "x")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::sumOperation() {
    QStringList list = { "i", "1", "=", "n", "x", "i", "SUB", "SUM" };

    SumOperation* expectedResult = new SumOperation(
        new EqualOperation(new Value(IDENTIFIER, "i"), new Value(NUMERIC, "1")),
        new Value(IDENTIFIER, "n"),
        new SubIndexOperation(new Value(IDENTIFIER, "x"), new Value(IDENTIFIER, "i"))
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::prodOperation() {
    QStringList list = { "i", "1", "=", "n", "x", "i", "SUB", "PROD" };

    ProdOperation* expectedResult = new ProdOperation(
        new EqualOperation(new Value(IDENTIFIER, "i"), new Value(NUMERIC, "1")),
        new Value(IDENTIFIER, "n"),
        new SubIndexOperation(new Value(IDENTIFIER, "x"), new Value(IDENTIFIER, "i"))
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::operationHasNotEnoughArguments() {
    QStringList list = {"x", "3", "+", "*"};

    try {
        ExpressionTreeNode* realResult = buildExpressionTree(list);
        QFAIL("The exception was not thrown");
    }
    catch (InvalidOperandCountException e) {
    }
}

void Test_buildExpressionTree::operationHasInvalidValue() {
    QStringList list = { "x", "3,4", "+", "*" };

    try {
        ExpressionTreeNode* realResult = buildExpressionTree(list);
        QFAIL("The exception was not thrown");
    }
    catch (InvalidValueException e) {
    }
}

void Test_buildExpressionTree::operationHasInvalidVariable() {
    QStringList list = { "x%", "3", "+", "*" };

    try {
        ExpressionTreeNode* realResult = buildExpressionTree(list);
        QFAIL("The exception was not thrown");
    }
    catch (InvalidValueException e) {
    }
}

void Test_buildExpressionTree::emptyTokens() {
    QStringList list = { };

    try {
        ExpressionTreeNode* realResult = buildExpressionTree(list);
        QFAIL("The exception was not thrown");
    }
    catch (EmptyExpressionException e) {
    }
}

void Test_buildExpressionTree::leftOperandIsOperation() {
    QStringList list = {"x", "3", "+", "3", "*"};

    MulOperation* expectedResult = new MulOperation(
        new PlusOperation(new Value(IDENTIFIER, "x"), new Value(NUMERIC, "3")),
        new Value(NUMERIC, "3")
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}

void Test_buildExpressionTree::rightOperandIsOperation() {
    QStringList list = { "3", "x", "3", "+", "*" };

    MulOperation* expectedResult = new MulOperation(
        new Value(NUMERIC, "3"),
        new PlusOperation(new Value(IDENTIFIER, "x"), new Value(NUMERIC, "3"))
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}


void Test_buildExpressionTree::allOperandsAreOperations() {
    QStringList list = { "3", "y", "-", "x", "3", "+", "*" };

    MulOperation* expectedResult = new MulOperation(
        new SubOperation(new Value(NUMERIC, "3"), new Value(IDENTIFIER, "y")),
        new PlusOperation(new Value(IDENTIFIER, "x"), new Value(NUMERIC, "3"))
        );

    ExpressionTreeNode* realResult = buildExpressionTree(list);

    testExpressionTree(realResult, expectedResult);
}


QTEST_APPLESS_MAIN(Test_buildExpressionTree)

#include "tst_test_buildexpressiontree.moc"
