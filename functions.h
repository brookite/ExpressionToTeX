#pragma once
#include <QString>


/*!
* \brief Разделяет входную строку на токены, соединенные в строке одним или несколькими белыми разделителями.
* \param[in] expression - строка, содержащая токены
* \return список токенов из строки
*/
QStringList getTokensByWhitespace(QString& expression);


/*!
* \brief Преобразует входную строку выражения, записанного в виде постфиксной (обратной польской) записи, в строку выражения в формате TeX
* \param[in] postfixExpression - строка выражения в постфиксной записи
* \return строка заданного выражения в формате TeX
*/
QString postfixExpressionToTeX(QString postfixExpression);
