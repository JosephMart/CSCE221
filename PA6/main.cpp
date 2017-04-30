#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>

#include "Graph.hpp"

int main(int argc, const char* argv[])
{
    try
    {
        if(argc != 2) throw std::invalid_argument("Usage: ./main <file name>");
        std::ifstream in(argv[1]);
        if(!in) throw std::invalid_argument("Invalid file name or unable to open file.");
        Graph g;
        g.buildGraph(in);
        g.displayGraph();
        if (g.grouping()) {
            int val1 = 0;
            int val2 = 0;

            std::cout << "Input any 2 Cities to find shortest path" << '\n';
            while (std::cin >> val1 && std::cin >> val2) {
                if(val1 <= g.vertices.size() && val1 >= 0 && val1 >= 0 && val2 < g.vertices.size())
                {
                    g.printShortestDistance(val1,val2);
                    std::cout << "2 More" << '\n';
                } else
                    break;
            }
        }

        return 0;
    }
    catch (std::exception& error)
    {
        std::cerr << "Error: " << error.what() << std::endl;
    }
}
