#include "expressions.h"
#include "operators.h"
#include "exceptions.h"
#include <QList>
#include <QStack>
#include <QRegularExpression>


Value* recognizeValueToken(QString token) {
    QRegularExpression numeric("^-?[0-9.]+$");
    QRegularExpression identifier("^[A-Za-z][A-Za-z_0-9]*$");

    Value* result = nullptr;
    if (numeric.match(token).hasMatch())
    // токен имеет только арабские цифры (0-9), знак дефиса и точку
    {
        result = new Value(NUMERIC, token);
    }
    else if (identifier.match(token).hasMatch())
    // токен имеет только арабские цифры (0-9), заглавные и строчные символы латинского алфавита,
    // знак нижнего подчеркивания, при этом переменная не может начинаться с цифры, знака нижнего подчеркивания
    {
        result = new Value(IDENTIFIER, token);
    }
    return result;
}
