#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph
{
public:
    Graph(int v);
    void AddEdge(int v, int w);
    void DFS_Recursive(int S);
private:
    int vertices;
    vector< list<int> > adjacencyList;
    vector<bool> visitedNode;
};

Graph::Graph(int v)
{
    vertices = v;
    adjacencyList.resize(v);
    visitedNode.resize(v, false);
}
void Graph::AddEdge(int v, int w)
{
    adjacencyList[v].push_back(w);
}

void Graph::DFS_Recursive(int vertex)
{
    visitedNode[vertex] = true;
    cout << vertex << " ";
    for(auto neighbour : adjacencyList[vertex])
    {
        DFS_Recursive(neighbour);
    }
    
}

int main()
{
    Graph g(7);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 3);
    g.AddEdge(1, 4);
    g.AddEdge(3, 5);
    g.AddEdge(2, 6);
    cout << "\nDFS - Recursive \n";
    g.DFS_Recursive(0);
	
}