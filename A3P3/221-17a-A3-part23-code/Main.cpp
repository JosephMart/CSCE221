//============================================================================
// Name        : Main.cpp
// Author      : Joseph Martinsen
// Date        : 19 March 2017
// Copyright   : JMM 2017
// Description : Handler Function for the Calulator Program
//============================================================================

#include "RuntimeException.h"
#include "Parser.h"
#include "Evaluator.h"

// Used to Check if parenthesis match
bool check_paren(std::string s);

int main() {
    /* implement user menu */
    char input;             // Store users choice
    bool infix = false;     // True if infix eq entered
    bool evaluated = false; // True if evalutation (5) has occured
    bool eCont = false;     // True if "Press enter to Continue" needs to be shown
    string eq;              // Store infix equation
    Parser par;             // Parser object
    double value;           // Store result of equation

    // Begin Menu loop
    do
    {
        system("clear");
        eCont = false;

        // Print Menu to the User
        std::cout << "Choose one of the following options" << '\n'
                  << "\t1: Read an infix expression from the keyboard" << '\n'
                  << "\t2: Check if parenthesis are balanced correctly" << '\n'
                  << "\t3: Display infix Expression" << '\n'
                  << "\t4: Display postfix Expression" << '\n'
                  << "\t5: Evaluate" << '\n'
                  << "\t6: Evaluate" << '\n'
                  << "Press q to quit\n" << '\n'
                  << "Choice: ";
        std::cin >> input;  // Get input from the User

        // Determine which option was chosen
        switch(input)
    	{
            case '1': // Read an infix expression from the keyboard
            {
                system("clear");
                std::cout << "Enter Your Equation in infix form\n" << '\n';
                std::cin >> eq;
                infix = true;
                evaluated = false; break;
            }
            case '2': // Check whether or not parenthesis are balanced correctly
            {
                system("clear");
                if (infix) {
                    std::cout << "Your Parehesis Matching is ";
                    if (check_paren(eq)) {
                        std::cout << "on point." << '\n';
                    } else
                        std::cout << "not correct." << '\n';
                }
                eCont = true; break;
            }
            case '3': // Display a correct infix expression on the screen or
                      // a message that the expression is invalid
            {
                system("clear");
                if (infix) {
                    std::cout << "Infix Expression: " << '\n';
                    std::cout << eq << '\n';
                }
                eCont = true; break;
            }
            case '4': // Convert infix form to its postfix form and display a
                      // postfix queue on the screen
            {
                system("clear");
                if (infix) {
                    par = Parser(eq);
                    std::cout << "Postfix Expression: " << '\n';
                    par.printPostfix();
                }
                eCont = true; break;
            }
            case '5': // Evaluate postfix form of the expression for floating
                      // point values entered from the keyboard
            {
                system("clear");
                if (infix) {
                    par = Parser(eq);
                    Evaluator e = Evaluator(par);
                    value = e.getValue();
                    evaluated = true;
                }
                eCont = true; break;
            }
            case '6': // Display the value of an algebraic expression on the screen
            {
                system("clear");
                if (evaluated)
                    std::cout << value << '\n';
                else if (infix)
                    std::cout << "Expression has not been Evaluated" << '\n';
                eCont = true; break;
            }
            case 'Q': // Quit
            case 'q':
                infix = true; break;
            default: // When user be stupid
            {
                cout << "Invalid Selection. Please try Again." << endl;
                eCont = true;
            }
        }
        if (!infix)
            std::cout << "Enter an infix expression first.\n" << '\n';
        if (eCont) {
            std::cout << "Press Enter to Continue..." << '\n';
            system("read");
        }
    } while(!((input == 'Q')||(input == 'q'))); // While User does not Quit
    return 0;
}

// Used to Check if parenthesis match
bool check_paren(std::string s)
{
    int numOpen = 0;
    int numClosed = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            numOpen++;
        if(s[i] == ')')
            numClosed++;
    }
    return numOpen == numClosed;
}
