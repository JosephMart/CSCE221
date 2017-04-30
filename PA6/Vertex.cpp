#include "Vertex.hpp"

Vertex::Vertex(int label)
{
    this->label = label;
}

Vertex::Vertex(int label, int parentLabel)
{
    this->label = label;
    this->parentLabel = parentLabel;
    edgeList.push_back(Edge(this->label, this->parentLabel, 1));
}

Vertex::Vertex(int label, std::list<Edge> edgeList)
{
    this->edgeList = edgeList;
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

bool operator != (const Vertex& v1, const Vertex& v2)
{
    return (v1.label != v2.label);
}
