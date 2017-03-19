#ifndef PARSER_H
#define PARSER_H

#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "RuntimeException.h"
#include <vector>


// Possible Tokens are (, ), +, -, *, /, ;, and floating point numbers.
// Data member kind stores the token itself for all but the numbers.
// Numbers are represented with kind '#' and the value stored in
// data member val (other tokens don't use val).
// ; means output the current value.
struct Token {
    char kind;
    double value;
    int weight;

    Token() : kind(), value(0), weight(get_operator_weight()) {}
    Token(char ch) : kind(ch), value(0), weight(get_operator_weight()) {}
    Token(char ch, int lb) : kind(ch), value(0), weight(lb) {}

    bool isOperator()
    {
        return kind == '+' || kind == '-' || kind == '*' || kind == '/' || kind == '^';
    }
    bool isOperand()
    {
        return isNum() || isVar();
    }
    bool isNum()
    {
        return kind >= '0' && kind <= '9';
    }
    bool isVar()
    {
        return kind >= 'a' && kind <= 'z';
    }
    void set_value(std::string word)
    {
        const char* c_word = word.c_str();
        value = atof(c_word);
    }
    void char_to_double()
    {
        value = (double)(kind - 48);
    }
    int get_operator_weight()
    {
        int weight = 0;
        switch(kind)
        {
            case '(':
            case ')':
                weight = 1;
                break;
            case '+':
            case '-':
                weight = 2;
                break;
            case '*':
            case '/':
                weight = 3;
                break;
            case '^':
                weight = 4;
                break;
        }
        return weight;
    }
};


class Parser {
private:
    /* declare constants */
    Token MULT;
    Token DIV;
    Token ADD;
    Token SUB;
    Token OPAR;
    Token CPAR;

    /* declare member variables;
    may include a string postfix queue and a integer operator stack */
    std::string infix;
    std::vector<Token> tokenList;
    LinkedStack<Token> opStack;
    LinkedQueue<Token> postfix;

    /* declare utility functions */
    LinkedStack<std::string> stringToStack(std::string s);
    LinkedQueue<Token> toPostfix();
    bool isOperator(char c);
    bool isOperand(char c);
    int operatorWeight(char c);
    void generateVec();
    void string_2_vec(std::string s)
{
    Token t;
    for(unsigned int i = 0; i < s.size(); i++)
    {
        t = Token(s[i]);
        if(t.isVar())
        {
            std::cout << "Enter value for " << t.kind << ": ";
            std::string word;
            std:cin >> word;
            t.set_value( word );
        }
        if(t.isNum())
        {
            t.char_to_double();
        }
        tokenList.push_back(t);
    }
    // return tokenList;
}

public:

    // constructor
    Parser(std::string s) : infix(s) {
        MULT = Token('*', 3);
        DIV  = Token('/', 3);
        ADD  = Token('+', 2);
        SUB  = Token('-', 2);
        OPAR = Token('(', 1);
        CPAR = Token(')', 1);
        toPostfix();
    }

    // accessor method
    LinkedQueue<Token> getPostfix() { return postfix; }

    // operations
    // void printInfix() { std::cout << infix << std::endl }
    // void printPostfix() { std::cout << postfix << '\n'; }
};

#endif
