#pragma once
#include <QTest>
#include <QObject>


class Test_recognizeValueToken : public QObject
{
    Q_OBJECT
private slots:
    void integerValue();
    void floatValue();
    void variableValue();
    void longVariableValue();
    void variableWithOnlyCaptialLetterValue();
    void variableWithCaptialLetterValue();
    void negativeIntegerValue();
    void negativeFloatValue();
    void zeroFloatValue();
    void zeroIntegerValue();
};
