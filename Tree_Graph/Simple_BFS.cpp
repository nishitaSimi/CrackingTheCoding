#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph
{
public:
    Graph(int v);
    void AddEdge(int v, int w);
    void BFS(int S);
private:
    int vertices;
    vector< vector<int> > adjacencyList;  
};

Graph::Graph(int v)
{
    vertices = v;
    adjacencyList.resize(v);
}
void Graph::AddEdge(int v, int w)
{
    adjacencyList[v].push_back(w);
}
void Graph::BFS(int S)
{
    vector<bool> visitedList;
    visitedList.resize(vertices, false);
    list<int> queue;
    queue.push_back(S);
    visitedList[S] = true;
    while(!queue.empty())
    {
        auto vertex = queue.front();
        cout << vertex << " ";
        queue.pop_front();
        for(auto neighbour : adjacencyList[vertex])
        {
            if(!visitedList[neighbour])
            {
                queue.push_back(neighbour);
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
    cout << "BFS\n";
    g.BFS(0);

	
}
