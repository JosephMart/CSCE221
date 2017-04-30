#ifndef Vertex_hpp
#define Vertex_hpp

#include <stdio.h>
#include <list>
#include <string>
#include <vector>

#include "Edge.hpp"

class Vertex
{
public:
    // the label of this vertex
    int label;
    // using a linked-list to manage its edges which offers O(c) insertion
    std::list<Edge> edgeList;

    // init your vertex here
    Vertex(int label);  //constructor

    // connect this vertex to a specific vertex (adding edge)
    void connectTo(int end);
};

bool operator == (const Vertex& v1, const Vertex& v2);

#endif /* Vertex_hpp */
