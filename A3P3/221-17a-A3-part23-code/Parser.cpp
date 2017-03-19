#include "Parser.h"

using namespace std;

/* initialize constants here */
// Parser::MULT = Token('*', 3);
// Parser::DIV  = Token('/', 3);
// Parser::ADD  = Token('+', 2);
// Parser::SUB  = Token('-', 2);
// Parser::OPAR = Token('(', 1);
// Parser::CPAR = Token(')', 1);

/* describe rest of functions */
LinkedQueue<Token> Parser::toPostfix() {
    // std::vector<Token> tokenList = { Token('2', 0), MULT, Token('2', 0)};
    string_2_vec("2+2+3");

    for (int i = 0; i < tokenList.size(); i++) {
        Token item = tokenList[i];

        if (item.isOperand())
            postfix.enqueue(item);
        else if (item.kind == ')') {
            Token topToken = opStack.pop();
            while (topToken.kind != '(') {
                postfix.enqueue(topToken);
                topToken = opStack.pop();
            }
        } else if (item.kind == '(')
            opStack.push(item);
         else {
            while (!(opStack.isEmpty()) && opStack.top().value >= item.value)
                postfix.enqueue(opStack.pop());
            opStack.push(item);
        }
    }
    while (!(opStack.isEmpty())) {
        postfix.enqueue(opStack.pop());
    }

    std::cout << postfix.dequeue().kind << '\n';
    std::cout << postfix.dequeue().kind << '\n';
    std::cout << postfix.dequeue().kind << '\n';
    std::cout << postfix.dequeue().kind << '\n';
    std::cout << postfix.dequeue().kind << '\n';
    return postfix;
}

// int Parser::GetOperatorWeight(char c)
// {
//     int weight = 0;
//     switch(c)
//     {
//         case '+':
//         case '-':
//             weight = 1;
//             break;
//         case '*':
//         case '/':
//             weight = 2;
//             break;
//         case '^':
//             weight = 3;
//             break;
//     }
//     return weight;
// }
