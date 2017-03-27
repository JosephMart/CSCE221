//============================================================================
// Name        : Evaluator.h
// Author      : Joseph Martinsen
// Date        : 19 March 2017
// Copyright   : JMM 2017
// Description : Header file for Evaluator
//============================================================================

#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Parser.h"
#include "LinkedQueue.h"
#include "LinkedStack.h"
#include "RuntimeException.h"
#include <cmath>
#include <sstream>

class Evaluator {
public:
  // user-defined exceptions
  class DivisionByZeroException : public RuntimeException {
    public:
      DivisionByZeroException() : RuntimeException("Division by zero") {}
  };
private:
  /* declare member variables;
    may include a string postfix queue and a double value stack */
    LinkedStack<double> doubleStack;
    LinkedQueue<Token> tokenQue;
    Parser& par;

    /* declare utility functions */
    double evaluate(char op, double val1, double val2 );

public:
    Evaluator(Parser& par) : par(par) {} // constructor
    double getValue(); // returns the result of expression evaluation
};

#endif
