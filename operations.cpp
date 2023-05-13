#include "expressions.h"
#include "operators.h"


struct PlusOperation : Operation {
	PlusOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return fillOperationPatternWithParentheses("%1 + %2", this);
	}

	virtual QString getOperationToken() {
		return "+";
	}

	virtual int getPriority() {
		return 0;
	}
};

struct SubOperation : Operation {
	SubOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return fillOperationPatternWithParentheses("%1 - %2", this);
	}

	virtual QString getOperationToken() {
		return "-";
	}

	virtual int getPriority() {
		return 0;
	}
};

struct MulOperation : Operation {
	MulOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		Value* leftValue = dynamic_cast<Value*>(getChild(0));
		Value* rightValue = dynamic_cast<Value*>(getChild(1));
		if (leftValue != nullptr && rightValue != nullptr) {
			if (leftValue->getType() == NUMERIC 
				&& rightValue->getType() == IDENTIFIER 
				&& rightValue->getValue().length() == 1) {
				return QString("%1%2").arg(leftValue->toTex(), rightValue->toTex());
			}
			else if (leftValue->getType() == IDENTIFIER 
				&& rightValue->getType() == NUMERIC 
				&& leftValue->getValue().length() == 1) {
				return QString("%1%2").arg(rightValue->toTex(), leftValue->toTex());
			}
		}
		return fillOperationPatternWithParentheses("%1 \\cdot %2", this);
	}

	virtual QString getOperationToken() {
		return "*";
	}

	virtual int getPriority() {
		return 2;
	}
};

struct DivOperation : Operation {
	DivOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return QString("\\frac{%1}{%2}").arg(getChild(0)->toTex(), getChild(1)->toTex());
	}

	virtual QString getOperationToken() {
		return "/";
	}

	virtual int getPriority() {
		return 2;
	}

};

struct LessOperation : Operation {
	LessOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return QString("%1 < %2").arg(getChild(0)->toTex(), getChild(1)->toTex());
	}

	virtual QString getOperationToken() {
		return "<";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct GreaterOperation : Operation {
	GreaterOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return QString("%1 > %2").arg(getChild(0)->toTex(), getChild(1)->toTex());
	}

	virtual QString getOperationToken() {
		return ">";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct GreaterEqualOperation : Operation {
	GreaterEqualOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return QString("%1 \\geq %2").arg(getChild(0)->toTex(), getChild(1)->toTex());
	}

	virtual QString getOperationToken() {
		return ">=";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct LessEqualOperation : Operation {
	LessEqualOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return QString("%1 \\leq %2").arg(getChild(0)->toTex(), getChild(1)->toTex());
	}

	virtual QString getOperationToken() {
		return "<=";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct EqualOperation : Operation {
	EqualOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return QString("%1 = %2").arg(getChild(0)->toTex(), getChild(1)->toTex());
	}

	virtual QString getOperationToken() {
		return "=";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct NotEqualOperation : Operation {
	NotEqualOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return QString("%1 \\neq %2").arg(getChild(0)->toTex(), getChild(1)->toTex());
	}

	virtual QString getOperationToken() {
		return "!=";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}

};

struct LogOperation : Operation {
	LogOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString getOperationToken() {
		return "LOG";
	}

	virtual QString toTex() {
		QString rightOperand = getChild(1)->toTex();
		if (getChild(1)->getChildrenCount() != 0) {
			rightOperand = getExpressionWithParentheses(rightOperand);
		}
		return QString("\\log_{%1}{%2}").arg(getChild(0)->toTex(), rightOperand);
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct SubIndexOperation : Operation {
	SubIndexOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return QString("{%1}_{%2}").arg(getChild(0)->toTex(), getChild(1)->toTex());
	}

	virtual QString getOperationToken() {
		return "SUB";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct LogicalAndOperation : Operation {
	LogicalAndOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return fillOperationPatternWithParentheses("%1 \\wedge %2", this);
	}

	virtual QString getOperationToken() {
		return "&";
	}

	virtual int getPriority() {
		return 2;
	}
};

struct LogicalOrOperation : Operation {
	LogicalOrOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return fillOperationPatternWithParentheses("%1 \\vee %2", this);
	}

	virtual QString getOperationToken() {
		return "|";
	}

	virtual int getPriority() {
		return 0;
	}

};

struct LogicalXorOperation : Operation {
	LogicalXorOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return fillOperationPatternWithParentheses("%1 \\oplus %2", this);
	}

	virtual QString getOperationToken() {
		return "XOR";
	}

	virtual int getPriority() {
		return 1;
	}
};

struct AllQuantifierOperation : Operation {
	AllQuantifierOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return QString("\\forall{%1}{(%2)}").arg(getChild(0)->toTex(), getChild(1)->toTex());
	}

	virtual QString getOperationToken() {
		return "FORALL";
	}

	virtual int getPriority() {
		return 0;
	}
};

struct ExistQuantifierOperation : Operation {
	ExistQuantifierOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return QString("\\exists{%1}{(%2)}").arg(getChild(0)->toTex(), getChild(1)->toTex());
	}

	virtual QString getOperationToken() {
		return "EXISTS";
	}

	virtual int getPriority() {
		return 0;
	}
};

struct ModOperation : Operation {
	ModOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		return fillOperationPatternWithParentheses("%1 \\bmod %2", this);
	}

	virtual QString getOperationToken() {
		return "%";
	}

	virtual int getPriority() {
		return 2;
	}
};

struct UnaryPlusOperation : Operation {
	UnaryPlusOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		QString operand = getChild(0)->toTex();
		if (getChild(0)->getChildrenCount() != 0) {
			operand = getExpressionWithParentheses(operand);
		}
		return QString("+%1").arg(operand);
	}

	virtual QString getOperationToken() {
		return "POS";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct UnaryMinusOperation : Operation {
	UnaryMinusOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		QString operand = getChild(0)->toTex();
		if (getChild(0)->getChildrenCount() != 0) {
			operand = getExpressionWithParentheses(operand);
		}
		return QString("-%1").arg(operand);
	}

	virtual QString getOperationToken() {
		return "NEG";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct LogicalInversionOperation : Operation {
	LogicalInversionOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		return QString("\\overline{%1}").arg(getChild(0)->toTex());
	}

	virtual QString getOperationToken() {
		return "~";
	}

	virtual int getPriority() {
		return 3;
	}
};

struct SinOperation : Operation {
	SinOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		QString operand = getChild(0)->toTex();
		if (getChild(0)->getChildrenCount() != 0) {
			operand = getExpressionWithParentheses(operand);
		}
		return QString("\\sin{%1}").arg(operand);
	}

	virtual QString getOperationToken() {
		return "SIN";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct CosOperation : Operation {
	CosOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		QString operand = getChild(0)->toTex();
		if (getChild(0)->getChildrenCount() != 0) {
			operand = getExpressionWithParentheses(operand);
		}
		return QString("\\cos{%1}").arg(operand);
	}

	virtual QString getOperationToken() {
		return "COS";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct TanOperation : Operation {
	TanOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		QString operand = getChild(0)->toTex();
		if (getChild(0)->getChildrenCount() != 0) {
			operand = getExpressionWithParentheses(operand);
		}
		return QString("\\tan{%1}").arg(operand);
	}

	virtual QString getOperationToken() {
		return "TG";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct CotanOperation : Operation {
	CotanOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		QString operand = getChild(0)->toTex();
		if (getChild(0)->getChildrenCount() != 0) {
			operand = getExpressionWithParentheses(operand);
		}
		return QString("\\cot{%1}").arg(operand);
	}

	virtual QString getOperationToken() {
		return "CTG";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct ArcsinOperation : Operation {
	ArcsinOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		QString operand = getChild(0)->toTex();
		if (getChild(0)->getChildrenCount() != 0) {
			operand = getExpressionWithParentheses(operand);
		}
		return QString("\\arcsin{%1}").arg(operand);
	}

	virtual QString getOperationToken() {
		return "ARCSIN";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct ArccosOperation : Operation {
	ArccosOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		QString operand = getChild(0)->toTex();
		if (getChild(0)->getChildrenCount() != 0) {
			operand = getExpressionWithParentheses(operand);
		}
		return QString("\\arccos{%1}").arg(operand);
	}

	virtual QString getOperationToken() {
		return "ARCCOS";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct ArctanOperation : Operation {
	ArctanOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		QString operand = getChild(0)->toTex();
		if (getChild(0)->getChildrenCount() != 0) {
			operand = getExpressionWithParentheses(operand);
		}
		return QString("\\arctan{%1}").arg(operand);
	}

	virtual QString getOperationToken() {
		return "ARCTG";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct ArccotanOperation : Operation {
	ArccotanOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		QString operand = getChild(0)->toTex();
		if (getChild(0)->getChildrenCount() != 0) {
			operand = getExpressionWithParentheses(operand);
		}
		return QString("\\arccot{%1}").arg(operand);
	}

	virtual QString getOperationToken() {
		return "ARCCTG";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct AbsOperation : Operation {
	AbsOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		return QString("|%1|").arg(getChild(0)->toTex());
	}

	virtual QString getOperationToken() {
		return "ABS";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct NaturalLogOperation : Operation {
	NaturalLogOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		QString operand = getChild(0)->toTex();
		if (getChild(0)->getChildrenCount() != 0) {
			operand = getExpressionWithParentheses(operand);
		}
		return QString("\\ln{%1}").arg(operand);
	}

	virtual QString getOperationToken() {
		return "LN";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct DecimalLogOperation : Operation {
	DecimalLogOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		QString operand = getChild(0)->toTex();
		if (getChild(0)->getChildrenCount() != 0) {
			operand = getExpressionWithParentheses(operand);
		}
		return QString("\\lg{%1}").arg(operand);
	}

	virtual QString getOperationToken() {
		return "LG";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct SqrtOperation : Operation {
	SqrtOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		return QString("\\sqrt{%1}").arg(getChild(0)->toTex());
	}

	virtual QString getOperationToken() {
		return "SQRT";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct RootOperation : Operation {
	RootOperation(ExpressionTreeNode* base, ExpressionTreeNode* value) : Operation({ base, value }) {}

	virtual QString toTex() {
		return QString("\\sqrt[{%1}]{%2}").arg(getChild(0)->toTex(), getChild(1)->toTex());
	}

	virtual QString getOperationToken() {
		return "ROOT";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};


struct PowOperation : Operation {
	PowOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		QString leftOperand = getChild(0)->toTex();
		if (getChild(0)->getChildrenCount() != 0) {
			leftOperand = getExpressionWithParentheses(leftOperand);
		}
		return QString("{%1}^{%2}").arg(leftOperand, getChild(1)->toTex());
	}

	virtual QString getOperationToken() {
		return "^";
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};

struct SumOperation : Operation {
public:
	SumOperation(ExpressionTreeNode* startInterval, ExpressionTreeNode* endInterval, ExpressionTreeNode* node)
		: Operation({ startInterval, endInterval, node }) {}

	SumOperation(ExpressionTreeNode* startInterval, ExpressionTreeNode* node)
		: Operation({ startInterval, node }) {}

	SumOperation(ExpressionTreeNode* node)
		: Operation({ node }) {}

	virtual QString toTex() {
		if (getChildrenCount() == 1) {
            ExpressionTreeNode * valueToSum = getChild(0);
            QString valueToSumString = valueToSum->toTex();
            if (valueToSum->getChildrenCount() > 0) {
                valueToSumString = getExpressionWithParentheses(valueToSumString);
            }
            return QString("\\sum{%2}").arg(valueToSumString);
		}
		else if (getChildrenCount() == 2) {
            ExpressionTreeNode * valueToSum = getChild(1);
            QString valueToSumString = valueToSum->toTex();
            if (valueToSum->getChildrenCount() > 0) {
                valueToSumString = getExpressionWithParentheses(valueToSumString);
            }
            return QString("\\sum_{%1}{%2}").arg(getChild(0)->toTex(), valueToSumString);
		}
		else if (getChildrenCount() == 3) {
            ExpressionTreeNode * valueToSum = getChild(2);
            QString valueToSumString = valueToSum->toTex();
            if (valueToSum->getChildrenCount() > 0) {
                valueToSumString = getExpressionWithParentheses(valueToSumString);
            }
            return QString("\\sum_{%1}^{%2}{%3}").arg(getChild(0)->toTex(), getChild(1)->toTex(), valueToSumString);
		}
	}

	virtual QString getOperationToken() {
		return "SUM";
	}

	virtual int getPriority() {
		return 0;
	}
};

struct ProdOperation : Operation {
public:
	ProdOperation(ExpressionTreeNode* startInterval, ExpressionTreeNode* endInterval, ExpressionTreeNode* node)
		: Operation({ startInterval, endInterval, node }) {}

	ProdOperation(ExpressionTreeNode* startInterval, ExpressionTreeNode* node)
		: Operation({ startInterval, node }) {}

	ProdOperation(ExpressionTreeNode* node)
		: Operation({ node }) {}

	virtual QString toTex() {
		if (getChildrenCount() == 1) {
            ExpressionTreeNode * valueToProd = getChild(0);
            QString valueToProdString = valueToProd->toTex();
            if (valueToProd->getChildrenCount() > 0) {
                valueToProdString = getExpressionWithParentheses(valueToProdString);
            }
            return QString("\\prod{%2}").arg(valueToProdString);
		}
		else if (getChildrenCount() == 2) {
            ExpressionTreeNode * valueToProd = getChild(1);
            QString valueToProdString = valueToProd->toTex();
            if (valueToProd->getChildrenCount() > 0) {
                valueToProdString = getExpressionWithParentheses(valueToProdString);
            }
            return QString("\\prod_{%1}{%2}").arg(getChild(0)->toTex(), valueToProdString);
		}
		else if (getChildrenCount() == 3) {
            ExpressionTreeNode * valueToProd = getChild(2);
            QString valueToProdString = valueToProd->toTex();
            if (valueToProd->getChildrenCount() > 0) {
                valueToProdString = getExpressionWithParentheses(valueToProdString);
            }
            return QString("\\prod_{%1}^{%2}{%3}").arg(getChild(0)->toTex(), getChild(1)->toTex(), valueToProdString);
		}
	}

	virtual QString getOperationToken() {
		return "PROD";
	}

	virtual int getPriority() {
		return 0;
	}
};
