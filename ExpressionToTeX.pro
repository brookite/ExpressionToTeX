QT -= gui
QT += testlib

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        expressions.cpp \
        main.cpp \
        operations.cpp \
        operators.cpp \
        tests/test_buildExpressionTree.cpp \
        tests/test_fillOperationPatternWithParentheses.cpp \
        tests/test_getExpressionWithParentheses.cpp \
        tests/test_getOperation.cpp \
        tests/test_getTokensByWhitespace.cpp \
        tests/test_isOperationToken.cpp \
        tests/test_postfixExpressionToTeX.cpp \
        tests/test_recognizeValueToken.cpp \
        tests/tests.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    exceptions.h \
    expressions.h \
    functions.h \
    operators.h \
    tests/test_buildExpressionTree.h \
    tests/test_fillOperationPatternWithParentheses.h \
    tests/test_getExpressionWithParentheses.h \
    tests/test_getOperation.h \
    tests/test_getTokensByWhitespace.h \
    tests/test_isOperationToken.h \
    tests/test_postfixExpressionToTeX.h \
    tests/test_recognizeValueToken.h \
    tests/tests.h
