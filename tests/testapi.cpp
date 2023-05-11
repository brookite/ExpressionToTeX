#include "testapi.h"
#include <QTest>

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