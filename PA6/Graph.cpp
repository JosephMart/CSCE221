#include "Graph.hpp"
#include <string>
#include <sstream>

Graph::Graph()
{
    adj_list = std::vector<std::list<Edge>>();
}

Graph::Graph(std::vector<std::list<Edge>> adjl)
{
    adj_list = adjl;
}

void Graph::buildGraph(std::ifstream& in)
{
    int i = 1;
    int buf, vertsNumber;
    in >> vertsNumber;
    for(int j = 0; j < vertsNumber; j++)
        vertices.push_back(Vertex(j));
    in >> vertsNumber;

    while(in.good() && i <= vertices.size())
    {
		while (in >> buf && buf != -1)
        {
            vertices.at(i-1).connectTo(buf);
        }
		adj_list.push_back(vertices.at(i-1).edgeList);
        i++;
    }
}

bool Graph::grouping(bool print)
{
    std::vector<int> group_a;
    std::vector<int> group_b;

    std::vector<int> color = std::vector<int>(vertices.size());
    for(unsigned int i = 0; i < color.size(); i++)
        color[i] = -1;

    color[0] = 1;

    std::queue<Vertex> q;
    q.push(vertices[0]);

    while(!q.empty())
    {
        Vertex v = q.front();
        q.pop();

        for(Edge e : v.edgeList)
        {
            if(color[e.end] == -1)
            {
                color[e.end] = 1 - color[e.start];
                q.push(vertices[e.end]);
            }
            else if(color[e.end] == color[e.start])
            {
                if (print) {
                    std::cout << "\nThe graph can not be seperated into 2 groups.\n";
                }
                return false;

            }
        }
    }
    for(unsigned int i = 0; i < color.size(); i++)
    {
        if(color[i] == 1)
            group_a.push_back(i);
        else
            group_b.push_back(i);
    }

    int max = group_a.size() > group_b.size() ? group_a.size() : group_b.size();

    if (print)
    {
        std::cout << "\nThe graph can be seperated into 2 groups.\n" << '\n'
                  <<"Group A\t" << "Group B\t" << '\n';

        for (int i = 0; i < max; i++) {
            try {
                std::cout << group_a.at(i);
            } catch(...) {}

            std::cout << '\t';
            try {
                std::cout << group_b.at(i);
            } catch(...) {}
            std::cout << '\n';
        }
    }
    std::cout << '\n';
    return true;
}

void Graph::displayGraph()
{
	for (auto v : this-> vertices)
	{
		std::cout << v.label << ':' << '\t';
		for(auto e : v.edgeList)
			std::cout << e.end << '\t';
		std::cout << '\n';
	}
}

void Graph::printShortestDistance(int v1, int v2)
{
    if(!grouping(false)) {return;}
    std::cout << "Calculating shortest distance from " << v1
              << " to " << v2 << '\n';
    shortestDistance(vertices.at(v2), vertices.at(v1));
}

std::vector<Vertex> Graph::shortestDistance(Vertex v1, Vertex v2)
{
    std::vector<Vertex> visited;
    std::queue<Vertex> q;
    Vertex current = v1;
    visited.push_back(current);
    q.push(current);

    while(!q.empty())
    {
        current = q.front();
        q.pop();
        if(current == v2)
        {
             Vertex temp = visited.at(std::find(visited.begin(), visited.end(), v2.label) - visited.begin());
             while (temp.label != v1.label) {
                 std::cout << temp.label << " --> ";
                 temp = visited.at(std::find(visited.begin(), visited.end(), temp.parentLabel) - visited.begin());
             }
             std::cout << temp.label << '\n';
            return visited;
        }
        for(Edge e : current.edgeList)
        {
            if(std::find(visited.begin(), visited.end(), e.end) == visited.end())
            {
                visited.push_back(Vertex(e.end, e.start ));
                q.push(Vertex(e.end, vertices[e.end].edgeList));
            }
        }
    }
    return visited;
}
