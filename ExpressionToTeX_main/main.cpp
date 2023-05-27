/*!
 * \file Файл с точкой входа в программу
 * \brief Содержит главную функцию main, в которой
   производится чтение из входного файла, преобразование выражения и запись в выходной файл или печать ошибки в консоль
*/

#include "functions.h"
#include "exceptions.h"
#include <QStringList>
#include <QFile>
#include <QTextStream>


int main(int argc, char *argv[])
{
    // Сообщения об ошибках
    QString inputArgsErr("Неверно указаны входной и выходной файлы. Возможно, один из них был пропущен");
    QString inputFileErr("Неверно указан файл с входными данными. Возможно, файл не существует");
    QString outputFileErr("Неверно указан файл для выходных данных. Возможно указанного расположения не существует или нет прав на запись.");
    QString lineCountErr("Программа принимает на вход файлы, состоящие из одной строки. Укажите только одну строку во входном файле");

    // Поток вывода ошибок в консоль
    QTextStream err(stdout);
    err.setCodec("cp866");

    try {
        if (argc < 2)
            // количество аргументов командной строки не соответствует требуемому количеству
        {
            // Вывести ошибку о неверно переданных аргументах командной строки
            err << inputArgsErr;
            return 1;
        }
        else {
            // Входной файл
            QString fileName(argv[1]);
            QFile inputFile(fileName);

            if (inputFile.exists())
                // файл существует
            {
                if (inputFile.open(QIODevice::ReadOnly))
                    // файл удалось открыть
                {
                    // Прочитать все данные из файла
                    QTextStream in(&inputFile);
                    QString inputData = in.readAll();

                    if (inputData.contains("\n"))
                        // во входном файле несколько строк
                    {
                        // Вывести ошибку о неверном количестве строк в файле
                        err << lineCountErr;
                        return 1;
                    }
                    else {
                        // Выходной файл
                        QFile outFile(argv[2]);
                        // Результат преобразования
                        QString result = postfixExpressionToTeX(inputData);

                        if (outFile.open(QIODevice::WriteOnly))
                            // выходной файл удалось открыть
                        {
                            // Записать полученную формулу в выходной файл
                            QTextStream out(&outFile);
                            out << result;
                        }
                        else {
                            // Выдать ошибку о невозможности записи в выходной файл
                            err << outputFileErr;
                            return 1;
                        }
                    }
                }
                inputFile.close();
            }
            else {
                // Вывести ошибку о невозможности чтения из входного файла
                err << inputFileErr;
                return 1;
            }
        }
    }
    catch (Exception e)
        // произошла ошибка
    {
        // Вывести сообщение этой ошибки в консоль
        err << e.getMessage();
        return 1;
    }

    return 0;
}
