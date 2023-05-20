QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_isoperationtoken.cpp  \
    $$files(../ExpressionToTeX_main/*.cpp)

SOURCES -= ../ExpressionToTeX_main/main.cpp

HEADERS += $$files(../ExpressionToTeX_main/*.h)

