#ifndef CALCULATORENGINE_H
#define CALCULATORENGINE_H

#include <QString>


class calculatorengine
{
public:
    calculatorengine();
    void clear();//clears the display
    void inputDigit(int digit);//Adds one number to current input 0...9
    void pressPlus();//User presses plus and record the operand
    void pressMinus();//User presses minus and record the operand
    void pressMuiltiply();//User presses multiply and record the operand
    void pressDivide();//User presses divide and record the operand
    void pressEquals();//calculates up to the last operand

    QString displayText()const;//Returns the text on the display

private:
    QString m_entryText = "0";//Display text/user input

    bool m_startNewEntry = true;//if true will begin a new number entry

    double m_accumulator = 0.0;






};

#endif // CALCULATORENGINE_H
