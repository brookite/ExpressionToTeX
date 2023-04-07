#pragma once
#include <QString>

enum ValueType {
    NUMERIC, IDENTIFIER
};


struct ExpressionTreeNode
{
public:
    ExpressionTreeNode(ExpressionTreeNode* left, ExpressionTreeNode* right)
    {
        this->left = left;
        this->right = right;
    };

    bool hasChildren() {
        return (left != nullptr) || (right != nullptr);
    }

    ExpressionTreeNode* leftNode() {
        return left;
    }

    ExpressionTreeNode* rightNode() {
        return right;
    }

    virtual QString toTex() = 0;

    virtual ~ExpressionTreeNode() {
        delete left;
        delete right;
    }
protected:
    ExpressionTreeNode* left = nullptr;
    ExpressionTreeNode* right = nullptr;
};


struct Operation : public ExpressionTreeNode
{
    Operation(ExpressionTreeNode* left, ExpressionTreeNode* right) : ExpressionTreeNode(left, right) {
    }

    bool isUnary() {
        return left == nullptr;
    }

    virtual int getPriority() = 0;
};


struct Value : public ExpressionTreeNode {
public:
    Value(ValueType type, QString value) : ExpressionTreeNode(nullptr, nullptr) {
        this->type = type;
        this->value = value;
    }

    QString getValue() {
        return value;
    }

    ValueType getType() {
        return type;
    }

    virtual QString toTex() {
        return value;
    }
protected:
    QString value;
    ValueType type;
};

/*! Строит дерево выражения по заданным токенам выражения, записанного в постфиксной (обратной польской) записи
* \param[in] tokens - токены выражения
* \return указатель на вершину дерева выражения
*/
ExpressionTreeNode* buildExpressionTree(QStringList& tokens);

/*! Создает объект значения по переданному токену, если токен соответствует значению
* \param[in] token - токен, соответствующий значению
* \return указатель на объект, представляющий собой значение, если токен соответствует значению, иначе - нулевой указатель
*/
Value* recognizeValueToken(QString token);

