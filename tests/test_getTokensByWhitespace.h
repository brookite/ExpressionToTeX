#pragma once
#include <QTest>
#include <QObject>


class Test_getTokensByWhitespace : public QObject
{
    Q_OBJECT
private slots:
    void tokensSeparatedByWhitespace();
    void onlyOneToken();
    void noTokens();
    void tokensSeparatedByTab();
    void oneOfTokenHasLengthGreaterThan1();
    void manyOfTokensHasLengthGreaterThan1();
    void allOfTokensHasLengthGreaterThan1();
    void manyOfTokensHasLengthGreaterThan1SeparatedByTab();
    void tokensSeparatedByWhitespaceAndTabs();
    void expresstionStartsWithWhitespaces();
    void expresstionStartsWithWhitespace();
    void expresstionEndsWithWhitespaces();
    void expresstionEndsWithWhitespace();
};
