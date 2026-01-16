#ifndef CALCULATORENGINE_H
#define CALCULATORENGINE_H

#include <QString>


class calculatorengine
{
public:
    calculatorengine();
    void clear();
    void inputDigit(int digit);
    void pressPlus();
    void pressEquals();
    QString displayText()const;
};

#endif // CALCULATORENGINE_H
