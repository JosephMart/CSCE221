#include "Evaluator.h"

using namespace std;

double Evaluator::evaluate(char op, double val1, double val2 )
{
    switch (op) {
        case '+':
            return val1 + val2;
        case '-':
            return val1 - val2;
        case '*':
            return val1 * val2;
        case '/':
            return val1/val2;
        case '^':
            return pow(val1,val2);
    }
}


double Evaluator::getValue() {
    /* returns the result of expression evaluation */
    tokenQue = par.getPostfix();
    while (tokenQue.first().kind != '#') {
        if (tokenQue.first().isNum()) {
            doubleStack.push(tokenQue.dequeue().value);
        } else if(tokenQue.first().isOperator()) {
            doubleStack.push(evaluate(tokenQue.dequeue().kind, doubleStack.pop(), doubleStack.pop()));
        } else
            return doubleStack.pop();
    }
}
