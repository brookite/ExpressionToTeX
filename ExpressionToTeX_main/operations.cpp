/*!
 * \file
 * \brief Файл с реализацией классов операций и учетом особенностей их представления в языке TeX
*/

#include "expressions.h"
#include "operators.h"


/*!
 * \brief Представление операции сложения в виде объекта
 */
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


/*!
 * \brief Представление операции вычитания в виде объекта
 */
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


/*!
 * \brief Представление операции умножения в виде объекта
 * \details Операнды, представляющие собой числовое значение и переменные представляются в итоговой формуле без знака умножения
 */
struct MulOperation : Operation {
	MulOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
        // Получить представление операции со знаком умножения
        QString result = fillOperationPatternWithParentheses("%1 \\cdot %2", this);

		Value* leftValue = dynamic_cast<Value*>(getChild(0));
		Value* rightValue = dynamic_cast<Value*>(getChild(1));
        if (leftValue != nullptr && rightValue != nullptr)
            // если операнды данной операции - значения
        {
			if (leftValue->getType() == NUMERIC 
				&& rightValue->getType() == IDENTIFIER 
                && rightValue->getValue().length() == 1)
            // если левый операнд - число, правый - переменная длины 1
            {
                // Считать результатом представление операции без знака умножения
                result = QString("%1%2").arg(leftValue->toTex(), rightValue->toTex());
			}
			else if (leftValue->getType() == IDENTIFIER 
				&& rightValue->getType() == NUMERIC 
                && leftValue->getValue().length() == 1)
                // если левый операнд - переменная длины 1, правый - число
            {
                // Считать результатом представление операции без знака умножения
                result = QString("%1%2").arg(rightValue->toTex(), leftValue->toTex());
            }
		}
        return result;
	}

	virtual QString getOperationToken() {
		return "*";
	}

	virtual int getPriority() {
		return 2;
	}
};


/*!
 * \brief Представление операции деления в виде объекта
 */
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


/*!
 * \brief Представление операции "меньше" в виде объекта
 */
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


/*!
 * \brief Представление операции "больше" в виде объекта
 */
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


/*!
 * \brief Представление операции "больше или равно" в виде объекта
 */
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


/*!
 * \brief Представление операции "меньше или равно" в виде объекта
 */
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


/*!
 * \brief Представление операции "равно" в виде объекта
 */
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


/*!
 * \brief Представление операции "не равно" в виде объекта
 */
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


/*!
 * \brief Представление операции логарифма по заданному основанию в виде объекта
 */
struct LogOperation : Operation {
	LogOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString getOperationToken() {
		return "LOG";
	}

	virtual QString toTex() {
		QString rightOperand = getChild(1)->toTex();
        if (getChild(1)->getChildrenCount() != 0)
            // правый операнд является составным
        {
            // Обернуть правый операнд в скобки
			rightOperand = getExpressionWithParentheses(rightOperand);
		}
		return QString("\\log_{%1}{%2}").arg(getChild(0)->toTex(), rightOperand);
	}

	virtual int getPriority() {
		return NO_PRIORITY;
	}
};


/*!
 * \brief Представление записи в нижний индекс в виде объекта
 */
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


/*!
 * \brief Представление логической операции "И" в виде объекта
 */
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

/*!
 * \brief Представление логической операции "ИЛИ" в виде объекта
 */
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

/*!
 * \brief Представление логической операции суммы по модулю в виде объекта
 */
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

/*!
 * \brief Представление записи квантора всеобщности в виде объекта
 */
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

/*!
 * \brief Представление записи квантора существования в виде объекта
 */
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

/*!
 * \brief Представление операции взятия остатка в виде объекта
 */
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

/*!
 * \brief Представление операции унарного плюса в виде объекта
 */
struct UnaryPlusOperation : Operation {
	UnaryPlusOperation(ExpressionTreeNode* value) : Operation({ value }) {}

	virtual QString toTex() {
		QString operand = getChild(0)->toTex();
        if (getChild(0)->getChildrenCount() != 0)
            // операнд является составным
        {
            // Обернуть операнд в скобки
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

/*!
 * \brief Представление операции унарного минуса в виде объекта
 */
struct UnaryMinusOperation : Operation {
	UnaryMinusOperation(ExpressionTreeNode* value) : Operation({ value }) {}

    virtual QString toTex() {
        QString operand = getChild(0)->toTex();
        if (getChild(0)->getChildrenCount() != 0)
        // операнд является составным
        {
            // Обернуть операнд в скобки
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

/*!
 * \brief Представление логической операции "НЕ" (инверсия) в виде объекта
 */
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

/*!
 * \brief Представление тригонометрической функции синуса в виде объекта
 */
struct SinOperation : Operation {
	SinOperation(ExpressionTreeNode* value) : Operation({ value }) {}

    virtual QString toTex() {
        QString operand = getChild(0)->toTex();
        if (getChild(0)->getChildrenCount() != 0)
        // операнд является составным
        {
            // Обернуть операнд в скобки
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

/*!
 * \brief Представление тригонометрической функции косинуса в виде объекта
 */
struct CosOperation : Operation {
	CosOperation(ExpressionTreeNode* value) : Operation({ value }) {}

    virtual QString toTex() {
        QString operand = getChild(0)->toTex();
        if (getChild(0)->getChildrenCount() != 0)
        // операнд является составным
        {
            // Обернуть операнд в скобки
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

/*!
 * \brief Представление тригонометрической функции тангенса в виде объекта
 */
struct TanOperation : Operation {
	TanOperation(ExpressionTreeNode* value) : Operation({ value }) {}

    virtual QString toTex() {
        QString operand = getChild(0)->toTex();
        if (getChild(0)->getChildrenCount() != 0)
        // операнд является составным
        {
            // Обернуть операнд в скобки
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

/*!
 * \brief Представление тригонометрической функции контангенса в виде объекта
 */
struct CotanOperation : Operation {
	CotanOperation(ExpressionTreeNode* value) : Operation({ value }) {}

    virtual QString toTex() {
        QString operand = getChild(0)->toTex();
        if (getChild(0)->getChildrenCount() != 0)
        // операнд является составным
        {
            // Обернуть операнд в скобки
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

/*!
 * \brief Представление тригонометрической функции арксинуса в виде объекта
 */
struct ArcsinOperation : Operation {
	ArcsinOperation(ExpressionTreeNode* value) : Operation({ value }) {}

    virtual QString toTex() {
        QString operand = getChild(0)->toTex();
        if (getChild(0)->getChildrenCount() != 0)
        // операнд является составным
        {
            // Обернуть операнд в скобки
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

/*!
 * \brief Представление тригонометрической функции арккосинуса в виде объекта
 */
struct ArccosOperation : Operation {
	ArccosOperation(ExpressionTreeNode* value) : Operation({ value }) {}

    virtual QString toTex() {
        QString operand = getChild(0)->toTex();
        if (getChild(0)->getChildrenCount() != 0)
        // операнд является составным
        {
            // Обернуть операнд в скобки
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

/*!
 * \brief Представление тригонометрической функции арктангенса в виде объекта
 */
struct ArctanOperation : Operation {
	ArctanOperation(ExpressionTreeNode* value) : Operation({ value }) {}

    virtual QString toTex() {
        QString operand = getChild(0)->toTex();
        if (getChild(0)->getChildrenCount() != 0)
        // операнд является составным
        {
            // Обернуть операнд в скобки
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

/*!
 * \brief Представление тригонометрической функции арккотангенса в виде объекта
 */
struct ArccotanOperation : Operation {
	ArccotanOperation(ExpressionTreeNode* value) : Operation({ value }) {}

    virtual QString toTex() {
        QString operand = getChild(0)->toTex();
        if (getChild(0)->getChildrenCount() != 0)
        // операнд является составным
        {
            // Обернуть операнд в скобки
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

/*!
 * \brief Представление операции модуля в виде объекта
 */
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

/*!
 * \brief Представление операции натурального логарифма в виде объекта
 */
struct NaturalLogOperation : Operation {
	NaturalLogOperation(ExpressionTreeNode* value) : Operation({ value }) {}

    virtual QString toTex() {
        QString operand = getChild(0)->toTex();
        if (getChild(0)->getChildrenCount() != 0)
        // операнд является составным
        {
            // Обернуть операнд в скобки
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

/*!
 * \brief Представление операции десятичного логарифма в виде объекта
 */
struct DecimalLogOperation : Operation {
	DecimalLogOperation(ExpressionTreeNode* value) : Operation({ value }) {}

    virtual QString toTex() {
        QString operand = getChild(0)->toTex();
        if (getChild(0)->getChildrenCount() != 0)
        // операнд является составным
        {
            // Обернуть операнд в скобки
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

/*!
 * \brief Представление операции квадратного корня в виде объекта
 */
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

/*!
 * \brief Представление операции корня по заданному основанию в виде объекта
 */
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

/*!
 * \brief Представление операции возведения в степень в виде объекта
 */
struct PowOperation : Operation {
	PowOperation(ExpressionTreeNode* left, ExpressionTreeNode* right) : Operation({ left, right }) {}

	virtual QString toTex() {
		QString leftOperand = getChild(0)->toTex();
        if (getChild(0)->getChildrenCount() != 0)
            // левый операнд - составной
        {
            // Обернуть левый операнд в скобки
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

/*!
 * \brief Представление операции суммирования в виде объекта
 * \details Операция суммирования может иметь нижний и верхний пределы суммирования,
   только нижний предел, или не иметь пределов суммирования
 */
struct SumOperation : Operation {
public:
	SumOperation(ExpressionTreeNode* startInterval, ExpressionTreeNode* endInterval, ExpressionTreeNode* node)
		: Operation({ startInterval, endInterval, node }) {}

	SumOperation(ExpressionTreeNode* startInterval, ExpressionTreeNode* node)
		: Operation({ startInterval, node }) {}

	SumOperation(ExpressionTreeNode* node)
		: Operation({ node }) {}

	virtual QString toTex() {
        if (getChildrenCount() == 1)
            // количество операндов операции - 1
        {
            ExpressionTreeNode * valueToSum = getChild(0);
            QString valueToSumString = valueToSum->toTex();
            if (valueToSum->getChildrenCount() > 0)
                // значение суммы является операцией
            {
                // Обернуть значение суммы в скобки
                valueToSumString = getExpressionWithParentheses(valueToSumString);
            }
            return QString("\\sum{%2}").arg(valueToSumString);
		}
        else if (getChildrenCount() == 2)
            // количество операндов операции - 2
        {
            ExpressionTreeNode * valueToSum = getChild(1);
            QString valueToSumString = valueToSum->toTex();
            if (valueToSum->getChildrenCount() > 0)
                // значение суммы является операцией
            {
                // Обернуть значение суммы в скобки
                valueToSumString = getExpressionWithParentheses(valueToSumString);
            }
            return QString("\\sum_{%1}{%2}").arg(getChild(0)->toTex(), valueToSumString);
		}
        else if (getChildrenCount() == 3)
            // количество операндов операции - 3
        {
            ExpressionTreeNode * valueToSum = getChild(2);
            QString valueToSumString = valueToSum->toTex();
            if (valueToSum->getChildrenCount() > 0)
                // значение суммы является операцией
            {
                // Обернуть значение суммы в скобки
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

/*!
 * \brief Представление произведения в виде объекта
 * \details Операция произведения может иметь нижний и верхний пределы,
   только нижний предел, или не иметь пределов произведения
 */
struct ProdOperation : Operation {
public:
	ProdOperation(ExpressionTreeNode* startInterval, ExpressionTreeNode* endInterval, ExpressionTreeNode* node)
		: Operation({ startInterval, endInterval, node }) {}

	ProdOperation(ExpressionTreeNode* startInterval, ExpressionTreeNode* node)
		: Operation({ startInterval, node }) {}

	ProdOperation(ExpressionTreeNode* node)
		: Operation({ node }) {}

	virtual QString toTex() {
        if (getChildrenCount() == 1)
            // количество операндов операции - 1
        {
            ExpressionTreeNode * valueToProd = getChild(0);
            QString valueToProdString = valueToProd->toTex();
            if (valueToProd->getChildrenCount() > 0)
                // значение произведения является операцией
            {
                // Обернуть значение произведения в скобки
                valueToProdString = getExpressionWithParentheses(valueToProdString);
            }
            return QString("\\prod{%2}").arg(valueToProdString);
		}
        else if (getChildrenCount() == 2)
            // количество операндов операции - 2
        {
            ExpressionTreeNode * valueToProd = getChild(1);
            QString valueToProdString = valueToProd->toTex();
            if (valueToProd->getChildrenCount() > 0)
                // значение произведения является операцией
            {
                // Обернуть значение произведения в скобки
                valueToProdString = getExpressionWithParentheses(valueToProdString);
            }
            return QString("\\prod_{%1}{%2}").arg(getChild(0)->toTex(), valueToProdString);
		}
        else if (getChildrenCount() == 3)
            // количество операндов операции - 3
        {
            ExpressionTreeNode * valueToProd = getChild(2);
            QString valueToProdString = valueToProd->toTex();
            if (valueToProd->getChildrenCount() > 0)
                // значение произведения является операцией
            {
                // Обернуть значение произведения в скобки
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
