#include "RuntimeException.h"
#include "Parser.h"
#include "Evaluator.h"

int main() {
    /* implement user menu */

    Parser test = Parser("5-3");

    Evaluator e = Evaluator(test);

    std::cout << e.getValue() << '\n';


    return 0;
}
