#include "Vertex.hpp"

Vertex::Vertex(int label)
{
    this->label = label;
}

void Vertex::connectTo(int end)
{
    edgeList.push_back(Edge(this->label, end, 1));
}
