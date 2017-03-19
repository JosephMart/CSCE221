#include "RuntimeException.h"
#include "Parser.h"
#include "Evaluator.h"

using namespace std;

int main() {
    /* implement user menu */
    LinkedQueue<int> lq = LinkedQueue<int>();
    lq.enqueue(5);
    lq.enqueue(6);
    lq.enqueue(7);
    lq.dequeue();
    std::cout << lq << '\n';

    LinkedStack<int> ls = LinkedStack<int>();

    ls.push(1);
    ls.push(2);
    ls.push(3);
    std::cout << ls << '\n';
    ls.pop();
    std::cout << ls << '\n';
    std::cout << ls.top() << '\n';

    return 0;
}
