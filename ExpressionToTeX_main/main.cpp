/*!
 * \file Файл с точкой входа в программу
 * \brief Содержит главную функцию main, в которой
 * производится чтение из входного файла, преобразование выражения и запись в выходной файл или печать ошибки в консоль
*/

#include "functions.h"
#include "exceptions.h"
#include <QStringList>
#include <QFile>
#include <QTextStream>


int main(int argc, char *argv[])
{
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
            QString fileName(argv[1]);
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
                        QFile outFile(argv[2]);
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
