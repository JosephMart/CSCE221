//============================================================================
// Name        : Parser.cpp
// Author      : Joseph Martinsen
// Date        : 19 March 2017
// Copyright   : JMM 2017
// Description : Handler Function for Parser and Token
//============================================================================

#include "Parser.h"

// Member functions for Token
bool Token::isOperator()
{
    return kind == '+' || kind == '-' || kind == '*' || kind == '/' || kind == '^';
}
bool Token::isOperand()
{
    return isNum() || isVar();
}
bool Token::isNum()
{
    return kind >= '0' && kind <= '9';
}
bool Token::isVar()
{
    return kind >= 'a' && kind <= 'z';
}
void Token::set_value(std::string word)
{
    const char* c_word = word.c_str();
    value = atof(c_word);
}
void Token::char_to_double()
{
    value = (double)(kind - 48);
}
int Token::get_operator_weight()
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

// Member functions for Parser
LinkedQueue<Token> Parser::toPostfix() {
    for (int i = 0; i < tokenList.size(); i++) {
        Token item = tokenList[i];

        if (!(opStack.isEmpty()) && item.isOperand())
            postfix.enqueue(item);
        else if (!(opStack.isEmpty()) && item.kind == ')') {
            Token topToken = opStack.pop();
            while (topToken.kind != '(') {
                postfix.enqueue(topToken);
                topToken = opStack.pop();
            }
        } else if( item.kind == '#') {
            while (!(opStack.isEmpty()))
                postfix.enqueue(opStack.pop());
        } else if (!(opStack.isEmpty()) && item.kind == '(')
            opStack.push(item);
         else {
            while (!(opStack.isEmpty()) && opStack.top().weight >= item.weight)
                postfix.enqueue(opStack.pop());
            opStack.push(item);
        }
    }
    while (!(opStack.isEmpty())) {
        postfix.enqueue(opStack.pop());
    }

    return postfix;
}


void Parser::getVec()
{
    Token t;
    for(int i = 0; i < infix.size(); i++)
    {
        t = Token(infix[i]);
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
}
