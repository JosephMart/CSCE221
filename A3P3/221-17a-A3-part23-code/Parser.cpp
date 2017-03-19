#include "Parser.h"

/* describe rest of functions */
LinkedQueue<Token> Parser::toPostfix() {
    string_2_vec("2*(2+3)");

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

    std::cout << postfix << '\n';
    return postfix;
}


void Parser::string_2_vec(std::string s)
{
    Token t;
    for(int i = 0; i < s.size(); i++)
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
}
