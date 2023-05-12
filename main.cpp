#include "functions.h"
#include "expressions.h"
#include "exceptions.h"
#include <QStringList>
#include <QTextCodec>
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
    // Разделить входную строку выражения на составные части (операции и операнды)
    QStringList tokens = getTokensByWhitespace(postfixExpression);
    // Преобразовать полученные элементы выражения в дерево выражения
    ExpressionTreeNode* exprTree = buildExpressionTree(tokens);
    // Преобразовать дерево выражения в строку выражения в формате TeX
    return exprTree->toTex();
}


int main(int argc, char *argv[])
{
    runTests();

    QString inputArgsErr("Неверно указаны входной и выходной файлы. Возможно, один из них был пропущен");
    QString inputFileErr("Неверно указан файл с входными данными. Возможно, файл не существует");
    QString outputFileErr("Неверно указан файл для выходных данных. Возможно указанного расположения не существует или нет прав на запись.");
    QString lineCountErr("Программа принимает на вход файлы, состоящие из одной строки. Укажите только одну строку во входном файле");

    QTextStream err(stdout);
    err.setCodec("cp866");

    try {
        if (argc < 2) {
            err << inputArgsErr;
            return 1;
        }
        else {
            QString fileName(argv[0]);
            QFile inputFile(fileName);
            if (inputFile.exists()) {
                if (inputFile.open(QIODevice::ReadOnly)) {
                    QTextStream in(&inputFile);
                    QString inputData = in.readAll();
                    if (inputData.contains("\n")) {
                        err << lineCountErr;
                        return 1;
                    }
                    else {
                        QFile outFile(argv[1]);
                        QString result = postfixExpressionToTeX(inputData);
                        if (outFile.open(QIODevice::WriteOnly)) {
                            QTextStream out(&outFile);
                            out << result;
                        }
                        else {
                            err << outputFileErr;
                            return 1;
                        }
                    }
                }
                inputFile.close();
            }
            else {
                err << inputFileErr;
                return 1;
            }
        }
    }
    catch (Exception e) {
        err << e.getMessage();
        return 1;
    }

    return 0;
}
