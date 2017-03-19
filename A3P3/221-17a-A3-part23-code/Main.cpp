#include "RuntimeException.h"
#include "Parser.h"
#include "Evaluator.h"


bool check_paren(std::string s);

int main() {
    /* implement user menu */

    // 1. Read an infix expression from the keyboard
    // 2. Check whether or not parenthesis are balanced correctly
    // 3. Display a correct infix expression on the screen or a message that the expression is invalid
    // 4. Convert infix form to its postfix form and display a postfix queue on the screen
    // 5. Evaluate postfix form of the expression for floating point values entered from the keyboard
    // 6. Display the value of an algebraic expression on the screen
    // string eq;
    // std::cout << "Enter Your Equation in Infix Form" << '\n';
    // std::cin >> eq;
    // Evaluator e = Evaluator(test);
    // std::cout << e.getValue() << '\n';

    char input;
    bool infix = false;
    bool evaluated = false;
    string eq;
    Parser par;
    double value;

    do
    {
        system("clear");
        bool eCont = false;

        std::cout << "Choose one of the following options" << '\n';
        std::cout << "\t1: Read an infix expression from the keyboard" << '\n';
        std::cout << "\t2: Check if parenthesis are balanced correctly" << '\n';
        std::cout << "\t3: Display infix Expression" << '\n';
        std::cout << "\t4: Display postfix Expression" << '\n';
        std::cout << "\t5: Evaluate" << '\n';
        std::cout << "\t6: 4 and 5 I guess??" << '\n';
        std::cout << "Press q to quit\n" << '\n';
        std::cout << "Choice: ";
        std::cin >> input;
        switch(input)
    	{
            case '1':
            {
                system("clear");
                std::cout << "Enter Your Equation in infix form\n" << '\n';
                std::cin >> eq;
                infix = true;
                evaluated = false;
                break;
            }
            case '2':
            {
                system("clear");
                if (infix) {
                    std::cout << "Your Parehesis Matching is ";
                    if (check_paren(eq)) {
                        std::cout << "on point." << '\n';
                    } else
                        std::cout << "not correct." << '\n';
                }
                eCont = true;
                break;
            }
            case '3':
            {
                system("clear");
                if (infix) {
                    std::cout << "Infix Expression: " << '\n';
                    par.printInfix();
                }
                eCont = true;
                break;
            }
            case '4':
            {
                system("clear");
                if (infix) {
                    par = Parser(eq);
                    std::cout << "Postfix Expression: " << '\n';
                    par.printPostfix();
                }
                eCont = true;
                break;
            }
            case '5':
            {
                system("clear");
                if (infix) {
                    par = Parser(eq);
                    Evaluator e = Evaluator(par);
                    value = e.getValue();
                    evaluated = true;
                }
                eCont = true;
                break;
            }
            case '6':
            {
                system("clear");
                if (evaluated)
                    std::cout << value << '\n';
                else
                    std::cout << "Expression has not been Evaluated" << '\n';
                eCont = true;
                break;
            }
            case 'Q':
            case 'q':
            {
                infix = true;
                break;

            }
            default:
                cout << "Invalid Selection. Please try Again." << endl;
        }
        if (!infix) {
            std::cout << "Enter an infix expression first.\n" << '\n';
        }
        if (eCont) {
            std::cout << "Press Enter to Continue..." << '\n';
            system("read");
        }
    } while(!((input == 'Q')||(input == 'q')));


    return 0;
}

bool check_paren(std::string s)
{
    int o = 0;
    int c = 0;
    for(unsigned int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            o++;
        if(s[i] == ')')
            c++;
    }
    if(o == c)
        return true;
    return false;
}
