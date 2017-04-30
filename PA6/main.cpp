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
        g.grouping();
        return 0;
    }
    catch (std::exception& error)
    {
        std::cerr << "Error: " << error.what() << std::endl;
    }
}
