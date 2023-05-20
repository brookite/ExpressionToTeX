/*!
 * \file
 * \brief Данный файл содержит реализацию основных функций программы:
 * для преобразования строки выражения в набор токенов, для
 * преобразования входной строки выражения в формулу на языке TeX
*/

#include "functions.h"
#include "expressions.h"


QStringList getTokensByWhitespace(QString & expression) {
    // Считать, что выходной список токенов пуст
    QStringList tokens;
    // Удалить белые разделители в начале и конце входной строки
    QString trimmedExpression = expression.trimmed();
    int tokenBegin = 0;
    int tokenLength = 0;
    for (int i = 0; i < trimmedExpression.length(); i++) {
        if (trimmedExpression.at(i).isSpace()) //символ является белым разделителем
        {
            //Сохранить полученный токен в результирующий список, если к нему отнесен хотя бы один из просмотренных символов
            if (tokenLength > 0) {
                tokens.append(trimmedExpression.mid(tokenBegin, tokenLength));
            }
            // Перейти к рассмотрению следующего токена
            tokenLength = 0;
            tokenBegin = i + 1;
        }
        else {
            // Отнести данный символ к текущему токену
            tokenLength++;
        }
    }
    // Записать последний токен из строки в результирующий список, если к нему отнесен хотя бы один из просмотренных символов
    if (tokenLength > 0) {
        tokens.append(trimmedExpression.mid(tokenBegin, tokenLength));
    }
    return tokens;
}

QString postfixExpressionToTeX(QString postfixExpression) {
    // Разделить входную строку выражения на составные части (операции и операнды)
    QStringList tokens = getTokensByWhitespace(postfixExpression);
    // Преобразовать полученные элементы выражения в дерево выражения
    ExpressionTreeNode* exprTree = buildExpressionTree(tokens);
    // Преобразовать дерево выражения в строку выражения в формате TeX
    return exprTree->toTex();
}

