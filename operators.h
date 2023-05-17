#pragma once
#include "expressions.h"

#define NO_PRIORITY -1


/*!
* \brief Создает узел операции по токену оператора и переданным операндам.
* \param[in] token - токен оператора
* \param[in] operands - операнды
* \return узел дерева, соответствующий данной операции
*/
Operation* getOperation(QString token, QList<ExpressionTreeNode*> operands);


/*!
* \brief Проверяет, является ли переданный токен оператором выражения и, в случае успешного распознавания, возвращает количество принимаемых операндов
* \param[in] token - токен, который необходимо проверить
* \param[out] operandCount - количество операндов операции
* \return логическое значение, показывающее является ли переданный токен оператором
*/
bool isOperationToken(QString token, int * operandCount);


/*!
* \brief Заполняет заданный шаблон операции, раставляя скобки, если это необходимо для однозначной интепретации операции
* \param[in] pattern - шаблон выражения операции. Аргументы, которые должны быть заменены, обозначаются в строке знаком “%” и порядковым номером аргумента
* \return строка, представляющее собой заданное выражение, заключенное в круглые скобки
*/
QString fillOperationPatternWithParentheses(QString pattern, Operation* currentOp);


/*!
* \brief Заключает заданное выражение в круглые скобки
* \param[in] pattern - выражение, которое необходимо преобразовать
* \return строка, представляющее собой заданное выражение, заключенное в круглые скобки
*/
QString getExpressionWithParentheses(QString expression);

