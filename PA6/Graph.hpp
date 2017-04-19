#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Edge.hpp"
#include "Vertex.hpp"

class Graph
{
public:
    // we use a vector to store vertices in the graph
    // and use label (int) to be a subscript to access a vertex
    std::vector<std::list<Edge>> adj_list; // adjacency list
    std::vector<Vertex> vertices;  // all vertices
    Graph(); // default constructor
    Graph(std::vector<std::list<Edge>> adjl); // constructor from adjl = adjacency list (optional)
    void buildGraph(std::ifstream& in);  // build a graph from the adjacency list
    void displayGraph();  // display the graph
};

#endif /* Graph_hpp */
