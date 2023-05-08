#pragma once
#include <QTest>
#include <QObject>


class Test_getExpressionWithParentheses : public QObject
{
    Q_OBJECT
private slots:
    void stringWithCharacters();
    void emptyString();
    void singleCharacterString();
    void stringAlreadyInParentheses();
};
