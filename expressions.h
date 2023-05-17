#pragma once
#include <QString>
#include <QList>

/*!
 * \brief Перечисление возможных типов значений токенов обратной польской записи
 */
enum ValueType {
    NUMERIC, // числовое значение
    IDENTIFIER // переменная
};

/*!
 * \brief Узел дерева выражения
 */
struct ExpressionTreeNode
{
public:
    /*!
     * \brief Конструктор узла дерева выражения
     * \param children - дочерние узлы данного узла дерева
     */
    ExpressionTreeNode(QList<ExpressionTreeNode*> children);

    /*!
     * \brief Получить дочерний узел по его индекс
     * \param index - индекс дочернего узла (начиная с 0)
     * \return дочерний узел, соответствующий индексу
     */
    ExpressionTreeNode* getChild(int index);

    /*!
     * \brief Возвращает количество дочерних узлов у данного узла дерева
     * \return количество дочерних узлов у данного узла дерева
     */
    virtual int getChildrenCount();

    /*!
     * \brief Преобразует узел дерева выражения в строку формулы на языке TeX
     * \return строка формулы на языке TeX
     */
    virtual QString toTex() = 0;

    /*!
     * \brief Деструктор узла дерева выражения
     */
    virtual ~ExpressionTreeNode();
protected:
    /*!
     * \brief Дочерние узлы дерева выражений
     */
    QList<ExpressionTreeNode*> children;
};

/*!
 * \brief Представление операции в виде объекта
 */
struct Operation : public ExpressionTreeNode
{
    /*!
     * \brief Конструктор операции
     * \param children - операнды операции
     */
    Operation(QList<ExpressionTreeNode*> children);

    /*!
     * \brief Получить токен данной операции в обратной польской записи
     * \return токен операции в обратной польской записи
     */
    virtual QString getOperationToken() = 0;

    /*!
     * \brief Получить приоритет данной операции
     * \return приоритет данной операции в виде целого числа (значение -1 - приоритет не учитывается)
     */
    virtual int getPriority() = 0;
};


/*!
 * \brief Представления значения в виде объекта
 */
struct Value : public ExpressionTreeNode {
public:
    /*!
     * \brief Конструктор значения
     * \param type - тип значения
     * \param value - токен значения
     */
    Value(ValueType type, QString value);

    /*!
     * \brief Получить значение
     * \return значение
     */
    QString getValue();

    /*!
     * \brief Получить тип значения
     * \return тип значения
     */
    ValueType getType();

    /*!
     * \brief Преобразовать значение в строку на языке TeX
     * \return строка значения на языке TeX
     */
    virtual QString toTex();
protected:
    /*!
     * \brief Значение
     */
    QString value;
    /*!
     * \brief Тип
     */
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

