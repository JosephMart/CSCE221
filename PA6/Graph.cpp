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
    std::string line;
    int i = 0;

    while(in.good())
    {
        getline(in, line);
        if(i == 0)
        {
            int vertsNumber = line[0] - '0';
            for(int j = 0; j < vertsNumber; j++)
                vertices.push_back(Vertex(j));
        } else if (i <= vertices.size())
        {
			int pos = i-1;
			int buf;
			std::stringstream ss(line);
			while (ss >> buf && buf != -1)
				vertices.at(pos).connectTo(buf);
			adj_list.push_back(vertices.at(pos).edgeList);
        }
        i++;
    }
}

bool Graph::grouping(bool print)
{
    std::vector<int> group_a;
    std::vector<int> group_b;

    for(Vertex v : vertices)
    {
        // Check if vertex is not in either group_a or group_b
        if(std::find(group_a.begin(), group_a.end(), v.label) == group_a.end() && std::find(group_b.begin(), group_b.end(), v.label) == group_b.end())
        {
            group_a.push_back(v.label);
            for(Edge e : v.edgeList)
            {
                if(std::find(group_b.begin(), group_b.end(), e.end) == group_b.end()) // if not found
                    group_b.push_back(e.end);
            }
        }
        // Check if vertex is in group_a and not group_b
        else if(std::find(group_a.begin(), group_a.end(), v.label) != group_a.end() && std::find(group_b.begin(), group_b.end(), v.label) == group_b.end())
        {
            for(Edge e : v.edgeList)
            {
                if(std::find(group_b.begin(), group_b.end(), e.end) == group_b.end()) // if not found
                    group_b.push_back(e.end);
            }
        }
        // Check if vertex is in group_b and not group_a
        else if(std::find(group_a.begin(), group_a.end(), v.label) == group_a.end() && std::find(group_b.begin(), group_b.end(), v.label) != group_b.end())
        {
            for(Edge e : v.edgeList)
            {
                if(std::find(group_a.begin(), group_a.end(), e.end) == group_a.end()) // if not found
                    group_a.push_back(e.end);
            }
        }
        else
        {
            if(print)
                std::cout << "The graph can not be seperated into 2 groups" << '\n';
            return false;
        }
    }

    int max = group_a.size() > group_b.size() ? group_a.size() : group_b.size();

    if (print)
    {
        std::cout << "The graph can be seperated into 2 groups\n" << '\n'
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
