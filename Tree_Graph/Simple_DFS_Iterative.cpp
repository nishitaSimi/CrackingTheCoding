#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph
{
public:
    Graph(int v);
    void AddEdge(int v, int w);
    void DFS(int S);
private:
    int vertices;
    vector< list<int> > adjacencyList;
};

Graph::Graph(int v)
{
    vertices = v;
    adjacencyList.resize(v);
}
void Graph::AddEdge(int v, int w)
{
    adjacencyList[v].push_front(w);
}
void Graph::DFS(int S)
{
    vector<bool> visitedList;
    visitedList.resize(vertices, false);
    list<int> stack;
    stack.push_front(S);
    visitedList[S] = true;
    while(!stack.empty())
    {
        auto vertex = stack.front();
        cout << vertex << " ";
        stack.pop_front();
        for(auto neighbour : adjacencyList[vertex])
        {
            if(!visitedList[neighbour])
            {
                stack.push_front(neighbour);
                visitedList[neighbour] = true;
            }
        }
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
    cout << "DFS\n";
    g.DFS(0);
	
}
