/*!
 * \file
 * \brief Основные исключения, необходимые для функционирования программы
*/

#pragma once
#include <QString>

/*!
 * \brief Исключение программы
 */
class Exception {
public:
    /*!
     * \brief Конструктор исключения
     * \param[in] message - сообщение исключения
     */
    Exception(QString message);

    /*!
     * \brief Получить сообщение исключения
     * \return сообщение исключения
     */
    QString getMessage();
protected:
    /*!
     * \brief сообщение исключения
     */
    QString message;
};

/*!
 * \brief Исключение пустого выражения
 */
class EmptyExpressionException : public Exception {
public:
    EmptyExpressionException(QString message);
};

/*!
 * \brief Исключение неверной операции
 */
class InvalidOperationException : public Exception {
public:
    InvalidOperationException(QString message);
};

/*!
* \brief Исключение неверного значения
*/
class InvalidValueException : public Exception {
public:
    InvalidValueException(QString message);
};

/*!
* \brief Исключение неверно количества операндов
*/
class InvalidOperandCountException : public Exception {
public:
    InvalidOperandCountException(QString message);
};
