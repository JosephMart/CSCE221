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
	// std::cin.ignore().get();
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
