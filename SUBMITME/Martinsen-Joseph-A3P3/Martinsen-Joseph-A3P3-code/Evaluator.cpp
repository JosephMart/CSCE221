//============================================================================
// Name        : Evaluator.cpp
// Author      : Joseph Martinsen
// Date        : 19 March 2017
// Copyright   : JMM 2017
// Description : Functions for Evaluator
//============================================================================

#include "Evaluator.h"

double Evaluator::evaluate(char op, double val1, double val2 )
// Evaluate 2 Operands and the respective operator
{
    switch (op) {
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        case '/':
            if (val2)
                return val1/val2;
            else{
                throw DivisionByZeroException();
            }
        case '^': return pow(val1,val2);
    }
}

double Evaluator::getValue() {
    /* returns the result of expression evaluation */
    tokenQue = par.getPostfix();
    int sign = 1;

    while (tokenQue.first().kind != '#')
        if (tokenQue.first().kind == '~') {
            sign = -1;
            tokenQue.dequeue();
        } else if (tokenQue.first().kind == ' ') {
            tokenQue.dequeue();
        } else if (tokenQue.first().isOperand()){
            double val;
            stringstream ss;
            do {
                ss << tokenQue.dequeue().value;
            } while(tokenQue.first().kind != ' ' || tokenQue.first().isOperand());
            ss >> val;
            val *= sign;
            sign = 1;
            doubleStack.push(val);
        }
        else if(tokenQue.first().isOperator())
            doubleStack.push(evaluate(tokenQue.dequeue().kind, doubleStack.pop(), doubleStack.pop()));
        else
            return doubleStack.pop();
}
