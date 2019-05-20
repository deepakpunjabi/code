#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Graph
{
    int v;
    list<int> *adj;
    // can use vector as well.
    // vector<int> *adj;
    // adj = new vector<int>[v];

  public:
    Graph(int v)
    {
        this->v = v;
        adj = new list<int>[v];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        // adj[v].push_back(u); // directed graph
    }

    bool isCyclicDriver()
    {
        vector<bool> visited(v, false);
        vector<bool> stacked(v, false);
        int source = 0;

        return isCyclic(source, visited, stacked);
    }

    bool isCyclic(int node, vector<bool> &visited, vector<bool> &stacked)
    {
        cout << "current node --> " << node << endl;
        visited[node] = true;
        stacked[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                return isCyclic(i, visited, stacked);
            }
            else
            {
                if (stacked[i])
                {
                    cout << "graph had cycle" << endl;
                    return true;
                }
            }
        }

        stacked[node] = false;
        return false;
    }

    void printGraph()
    {
        for (int i = 0; i < v; ++i)
        {
            cout << i << " --> ";
            for (auto j : adj[i])
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    // g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    // g.printGraph();

    if (g.isCyclicDriver())
    {
        cout << "Graph contains cycle" << endl;
    }

    else
    {
        cout << "Graph doesn't contain cycle" << endl;
    }

    return 0;
}
