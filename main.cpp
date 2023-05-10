#include "functions.h"
#include <QStringList>
#include "tests/tests.h"

QStringList getTokensByWhitespace(QString & expression) {
    // Считать, что выходной список токенов пуст
    QStringList tokens;
    // Удалить белые разделители в начале и конце входной строки
    QString trimmedExpression = expression.trimmed();
    int tokenBegin = 0;
    int tokenLength = 0;
    for (int i = 0; i < expression.length(); i++) {
        if (expression.at(i).isSpace()) //символ является белым разделителем
        {
            //Сохранить полученный токен в результирующий список, если к нему отнесен хотя бы один из просмотренных символов
            if (tokenLength > 0) {
                tokens.append(expression.mid(tokenBegin, tokenLength));
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
        tokens.append(expression.mid(tokenBegin, tokenLength));
    }
    return tokens;
}

QString postfixExpressionToTeX(QString postfixExpression) {
    return "";
}


int main(int argc, char *argv[])
{
    runTests();
    return 0;
}
