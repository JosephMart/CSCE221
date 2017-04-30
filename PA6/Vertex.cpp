#include "Vertex.hpp"

Vertex::Vertex(int label)
{
    this->label = label;
}

void Vertex::connectTo(int end)
{
    edgeList.push_back(Edge(this->label, end, 1));
}


bool operator == (const Vertex& v1, const Vertex& v2)
{
    return (v1.label == v2.label);
}
