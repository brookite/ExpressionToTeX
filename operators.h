#pragma once
#include "expressions.h"

#define NO_PRIORITY -1


/*! Создает узел унарной операции по токену оператора и переданным операторам.
* \param[in] token - токен оператора
* \param[in] operand - операнд
* \return узел дерева, соответствующий данной операции
*/
Operation* getOperation(QString& token, ExpressionTreeNode* operand);

/*! Создает узел бинарной операции по токену оператора и переданным операторам
* \param[in] token - токен оператора
* \param[in] leftOperand - левый операнд
* \param[in] rightOperand - правый операнд
* \return узел дерева, соответствующий данной операции
*/
Operation* getOperation(QString& token, ExpressionTreeNode* leftOperand, ExpressionTreeNode* rightOperand);

/*! Проверяет, является ли переданный токен оператором выражения и, в случае успешного распознавания, проверяет, является ли операция унарной
* \param[in] token - токен, который необходимо проверить
* \param[out] isUnary - является ли операция унарной
* \return логическое значение, показывающее является ли переданный токен оператором
*/
bool isOperationToken(QString& token, bool* isUnary);

/*! Проверяет, является ли переданный токен оператором, содержащим в себе два соответствующих операции аргумента
* \param[in] token - токен, который необходимо проверить
* \param[out] opName - имя оператора
* \param[out] firstArgument - значение первого аргумента
* \param[out] secondArgument - значение второго аргумента
* \return логическое значение, показывающее является ли переданный токен оператором, содержащим аргументы
*/
bool recognizeOperationWithArguments(QString token, QString* opName, QString* firstArgument, QString* secondArgument);