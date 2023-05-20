
#include <QtTest>
#include "../ExpressionToTeX_main/functions.h"


class Test_postfixExpressionToTex : public QObject
{
    Q_OBJECT
private slots:
    void fewOperationsWithoutParentheses();
    void fewOperationsWithLeftOperandInParentheses();
    void fewOperationsWithRightOperandInParentheses();
    void fewOperationsWithAllOperandsInParentheses();
    void tabSeparator();
    void variablesInExpression();
    void longVariablesInExpression();
    void multiplyNumberAndVariableExpression();
    void multiplyVariableAndNumberExpression();
    void onlyFloatNumbersInExpression();
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
    void sumOperationWithoutEndInterval();
    void prodOperationWithoutEndInterval();
    void sumOperationWithoutIntervals();
    void prodOperationWithoutIntervals();
    void integerValueInExpression();
    void floatValueInExpression();
    void variableInExpression();
    void longVariableInExpression();
    void complexTest1();
    void complexTest2();
};


void Test_postfixExpressionToTex::fewOperationsWithoutParentheses() {
    QString inputExpression = "3 4 * 5 +";
    QString expectedResult = "3 \\cdot 4 + 5";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::fewOperationsWithLeftOperandInParentheses() {
    QString inputExpression = "3 4 + 5 *";
    QString expectedResult = "(3 + 4) \\cdot 5";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::fewOperationsWithRightOperandInParentheses() {
    QString inputExpression = "5 3 4 + *";
    QString expectedResult = "5 \\cdot (3 + 4)";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::fewOperationsWithAllOperandsInParentheses() {
    QString inputExpression = "5 4 - 3 4 + *";
    QString expectedResult = "(5 - 4) \\cdot (3 + 4)";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::tabSeparator() {
    QString inputExpression = "3\t4\t*\t5\t+";
    QString expectedResult = "3 \\cdot 4 + 5";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::variablesInExpression() {
    QString inputExpression = "x y * z +";
    QString expectedResult = "x \\cdot y + z";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::longVariablesInExpression() {
    QString inputExpression = "var 4 * 5 +";
    QString expectedResult = "var \\cdot 4 + 5";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::multiplyNumberAndVariableExpression() {
    QString inputExpression = "3 x *";
    QString expectedResult = "3x";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::multiplyVariableAndNumberExpression() {
    QString inputExpression = "x 3 *";
    QString expectedResult = "3x";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::onlyFloatNumbersInExpression() {
    QString inputExpression = "3.05 4.5 * 5.3 +";
    QString expectedResult = "3.05 \\cdot 4.5 + 5.3";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::plusOperation() {
    QString inputExpression = "x 3 +";
    QString expectedResult = "x + 3";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}


void Test_postfixExpressionToTex::subOperation() {
    QString inputExpression = "x 3 -";
    QString expectedResult = "x - 3";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}


void Test_postfixExpressionToTex::mulOperation() {
    QString inputExpression = "3 4 *";
    QString expectedResult = "3 \\cdot 4";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::divOperation() {
    QString inputExpression = "7 x /";
    QString expectedResult = "\\frac{7}{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::lessOperation() {
    QString inputExpression = "x 3 <";
    QString expectedResult = "x < 3";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::greaterOperation() {
    QString inputExpression = "x 3 >";
    QString expectedResult = "x > 3";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::lessOrEqualOperation() {
    QString inputExpression = "x 3 <=";
    QString expectedResult = "x \\leq 3";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::greaterOrEqualOperation() {
    QString inputExpression = "x 3 >=";
    QString expectedResult = "x \\geq 3";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::notEqualOperation() {
    QString inputExpression = "x 3 !=";
    QString expectedResult = "x \\neq 3";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::logOperation() {
    QString inputExpression = "3 x LOG";
    QString expectedResult = "\\log_{3}{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::powOperation() {
    QString inputExpression = "2 x ^";
    QString expectedResult = "{2}^{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::subIndexOperation() {
    QString inputExpression = "x i SUB";
    QString expectedResult = "{x}_{i}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::logicalAndOperation() {
    QString inputExpression = "x 3 &";
    QString expectedResult = "x \\wedge 3";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::logicalOrOperation() {
    QString inputExpression = "x 3 |";
    QString expectedResult = "x \\vee 3";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::logicalXorOperation() {
    QString inputExpression = "x 3 XOR";
    QString expectedResult = "x \\oplus 3";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::allQuantifierOperation() {
    QString inputExpression = "x x 3 < FORALL";
    QString expectedResult = "\\forall{x}{(x < 3)}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::existQuantifierOperation() {
    QString inputExpression = "y y 5 > EXISTS";
    QString expectedResult = "\\exists{y}{(y > 5)}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::modOperation() {
    QString inputExpression = "x 3 %";
    QString expectedResult = "x \\bmod 3";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::unaryPlusOperation() {
    QString inputExpression = "x POS";
    QString expectedResult = "+x";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::unaryMinusOperation() {
    QString inputExpression = "x NEG";
    QString expectedResult = "-x";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::inversionOperation() {
    QString inputExpression = "x !";
    QString expectedResult = "\\overline{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::sinOperation() {
    QString inputExpression = "x SIN";
    QString expectedResult = "\\sin{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}


void Test_postfixExpressionToTex::cosOperation() {
    QString inputExpression = "x COS";
    QString expectedResult = "\\cos{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}


void Test_postfixExpressionToTex::tanOperation() {
    QString inputExpression = "x TG";
    QString expectedResult = "\\tan{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}


void Test_postfixExpressionToTex::cotanOperation() {
    QString inputExpression = "x CTG";
    QString expectedResult = "\\cot{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::arcsinOperation() {
    QString inputExpression = "x ARCSIN";
    QString expectedResult = "\\arcsin{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}


void Test_postfixExpressionToTex::arccosOperation() {
    QString inputExpression = "x ARCCOS";
    QString expectedResult = "\\arccos{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}


void Test_postfixExpressionToTex::arctanOperation() {
    QString inputExpression = "x ARCTG";
    QString expectedResult = "\\arctan{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}


void Test_postfixExpressionToTex::arccotanOperation() {
    QString inputExpression = "x ARCCTG";
    QString expectedResult = "\\arccot{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::absOperation() {
    QString inputExpression = "x ABS";
    QString expectedResult = "|x|";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::lnOperation() {
    QString inputExpression = "x LN";
    QString expectedResult = "\\ln{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::lgOperation() {
    QString inputExpression = "x LG";
    QString expectedResult = "\\lg{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::rootOperation() {
    QString inputExpression = "3 x ROOT";
    QString expectedResult = "\\sqrt[{3}]{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::sqrtOperation() {
    QString inputExpression = "x SQRT";
    QString expectedResult = "\\sqrt{x}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::sumOperation() {
    QString inputExpression = "i 1 = n x i SUB SUM";
    QString expectedResult = "\\sum_{i = 1}^{n}{({x}_{i})}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::prodOperation() {
    QString inputExpression = "k 1 = n x i SUB PROD";
    QString expectedResult = "\\prod_{k = 1}^{n}{({x}_{i})}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::sumOperationWithoutEndInterval() {
    QString inputExpression = "i 1 = x i SUB SUM2";
    QString expectedResult = "\\sum_{i = 1}{({x}_{i})}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::prodOperationWithoutEndInterval() {
    QString inputExpression = "i 1 = x i SUB PROD2";
    QString expectedResult = "\\prod_{i = 1}{({x}_{i})}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::sumOperationWithoutIntervals() {
    QString inputExpression = "x i SUB SUM1";
    QString expectedResult = "\\sum{({x}_{i})}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::prodOperationWithoutIntervals() {
    QString inputExpression = "x i SUB PROD1";
    QString expectedResult = "\\prod{({x}_{i})}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::integerValueInExpression() {
    QString inputExpression = "4";
    QString expectedResult = "4";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::floatValueInExpression() {
    QString inputExpression = "3.14";
    QString expectedResult = "3.14";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::variableInExpression() {
    QString inputExpression = "y";
    QString expectedResult = "y";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::longVariableInExpression() {
    QString inputExpression = "var";
    QString expectedResult = "var";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::complexTest1() {
    QString inputExpression = "i 0 = n x i SUB y i SUB * e / SUM z + a 2 ^ -";
    QString expectedResult = "\\sum_{i = 0}^{n}{(\\frac{{x}_{i} \\cdot {y}_{i}}{e})} + z - {a}^{2}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}

void Test_postfixExpressionToTex::complexTest2() {
    QString inputExpression = "i 1 = n j 1 = m 3 y j SUB * x i SUB + SUM SUM";
    QString expectedResult = "\\sum_{i = 1}^{n}{(\\sum_{j = 1}^{m}{(3 \\cdot {y}_{j} + {x}_{i})})}";
    QString realResult = postfixExpressionToTeX(inputExpression);

    QCOMPARE(expectedResult, realResult);
}


QTEST_APPLESS_MAIN(Test_postfixExpressionToTex)

#include "tst_test_postfixexpressiontotex.moc"
