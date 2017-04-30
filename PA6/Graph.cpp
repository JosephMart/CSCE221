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

void Graph::grouping()
{
    std::vector<int> group_a;
    std::vector<int> group_b;
    bool broke = false;

    for(Vertex v : vertices)
    {
        // if not in either group_a or group_b
        if(std::find(group_a.begin(), group_a.end(), v.label) == group_a.end() && std::find(group_b.begin(), group_b.end(), v.label) == group_b.end())
        {
            group_a.push_back(v.label);
            for(Edge e : v.edgeList)
            {
                if(std::find(group_b.begin(), group_b.end(), e.end) == group_b.end()) // if not found
                {
                    group_b.push_back(e.end);
                }
            }
        }
        // if in group_a and not group_b
        else if(std::find(group_a.begin(), group_a.end(), v.label) != group_a.end() && std::find(group_b.begin(), group_b.end(), v.label) == group_b.end())
        {
            for(Edge e : v.edgeList)
            {
                if(std::find(group_b.begin(), group_b.end(), e.end) == group_b.end()) // if not found
                {
                    group_b.push_back(e.end);
                }
            }
        }
        // if in group_b and not group_a
        else if(std::find(group_a.begin(), group_a.end(), v.label) == group_a.end() && std::find(group_b.begin(), group_b.end(), v.label) != group_b.end())
        {
            for(Edge e : v.edgeList)
            {
                if(std::find(group_a.begin(), group_a.end(), e.end) == group_a.end()) // if not found
                {
                    group_a.push_back(e.end);
                }
            }
        }
        else
        {
            broke = true;
        }
    }

    std::cout << "here ia m" << '\n';
    if (!broke)
    {
        std::cout << "Group A\t" << "Group B\t" << '\n';
        for (int i = 0; i < group_a.size(); i++) {
            std::cout << group_a.at(i) << '\t' << group_b.at(i) << '\n';
        }
    }
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
