//============================================================================
// Name        : Parser.h
// Author      : Joseph Martinsen
// Date        : 19 March 2017
// Copyright   : JMM 2017
// Description : Headler File for Token and Parser
//============================================================================

#ifndef PARSER_H
#define PARSER_H

#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "RuntimeException.h"
#include <vector>

// Token Struct
struct Token {
    char kind;
    double value;
    int weight;

    Token() : kind(), value(0), weight(get_operator_weight()) {}
    Token(char ch) : kind(ch), value(0), weight(get_operator_weight()) {}
    Token(char ch, int lb) : kind(ch), value(0), weight(lb) {}

    bool isOperator();
    bool isOperand();
    bool isNum();
    bool isVar();
    void set_value(std::string word);
    void char_to_double();
    int get_operator_weight();
};


class Parser {
private:
    /* declare constants */
    Token MULT; // Multiply
    Token DIV;  // Division
    Token ADD;  // Addition
    Token SUB;  // Subtract
    Token OPAR; // Open Parenthesis
    Token CPAR; // Close Parenthesis

    /* declare member variables;
    may include a string postfix queue and a integer operator stack */
    std::string infix;
    std::vector<Token> tokenList;
    LinkedStack<Token> opStack;
    LinkedQueue<Token> postfix;

    /* declare utility functions */
    LinkedStack<std::string> stringToStack(std::string s);
    LinkedQueue<Token> toPostfix();
    int operatorWeight(char c);
    void getVec();

public:
    // constructor
    Parser() : infix("") {}
    Parser(std::string s) : infix(s) {
        MULT = Token('*', 3);
        DIV  = Token('/', 3);
        ADD  = Token('+', 2);
        SUB  = Token('-', 2);
        OPAR = Token('(', 1);
        CPAR = Token(')', 1);
        opStack.push(Token('#'));
        getVec();
        toPostfix();
    }

    // accessor method
    LinkedQueue<Token> getPostfix() { return postfix; }

    // operations
    void printInfix() { std::cout << infix << '\n'; }
    void printPostfix() { std::cout << postfix << '\n'; }
};

#endif
