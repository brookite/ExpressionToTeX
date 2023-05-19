/*!
 * \file
 * \brief Файл с реализацией исключений, необходимых для программы
*/

#include "exceptions.h"


Exception::Exception(QString message) {
    this->message = message;
}

QString Exception::getMessage() {
    return this->message;
}

EmptyExpressionException::EmptyExpressionException(QString message) : Exception(message) {}

InvalidOperationException::InvalidOperationException(QString message) : Exception(message) {}

InvalidValueException::InvalidValueException(QString message) : Exception(message) {}

InvalidOperandCountException::InvalidOperandCountException(QString message) : Exception(message) {}
