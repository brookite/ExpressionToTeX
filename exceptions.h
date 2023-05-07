#pragma once
#include <QString>


class Exception {
public:
    Exception(QString message) {
        this->message = message;
    }

    QString getMessage() {
        return this->message;
    }
protected:
    QString message;
};


class EmptyExpressionException : public Exception {
public:
    EmptyExpressionException(QString message) : Exception(message) {}
};


class InvalidOperationException : public Exception {
public:
    InvalidOperationException(QString message) : Exception(message) {}
};


class InvalidValueException : public Exception {
public:
    InvalidValueException(QString message) : Exception(message) {}
};


class InvalidOperandCountException : public Exception {
public:
    InvalidOperandCountException(QString message) : Exception(message) {}
};
