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
            else
                throw DivisionByZeroException();
        case '^': return pow(val1,val2);
    }
}

double Evaluator::getValue() {
    /* returns the result of expression evaluation */
    tokenQue = par.getPostfix();
    while (tokenQue.first().kind != '#')
        if (tokenQue.first().isOperand())
            doubleStack.push(tokenQue.dequeue().value);
        else if(tokenQue.first().isOperator())
            doubleStack.push(evaluate(tokenQue.dequeue().kind, doubleStack.pop(), doubleStack.pop()));
        else
            return doubleStack.pop();
}
