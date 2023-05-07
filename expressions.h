#pragma once
#include <QString>
#include <QList>

enum ValueType {
    NUMERIC, IDENTIFIER
};


struct ExpressionTreeNode
{
public:
    ExpressionTreeNode(QList<ExpressionTreeNode*> children)
    {
        this->children = children;
    };

    ExpressionTreeNode* getChild(int index) {
        return children.at(index);
    }

    virtual int getChildrenCount() {
        return children.length();
    }

    virtual QString toTex() = 0;

    virtual ~ExpressionTreeNode() {
        for (int i = 0; i < children.length(); i++) {
            delete children.at(i);
        }
    }
protected:
    QList<ExpressionTreeNode*> children;
};


struct Operation : public ExpressionTreeNode
{
    Operation(QList<ExpressionTreeNode*> children) : ExpressionTreeNode(children) {
    }

    virtual QString getOperationToken() = 0;
    virtual int getPriority() = 0;
};


struct Value : public ExpressionTreeNode {
public:
    Value(ValueType type, QString value) : ExpressionTreeNode({}) {
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

