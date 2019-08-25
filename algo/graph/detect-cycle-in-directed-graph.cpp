#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int v;
    list<int> *adj;
    // can use vector as well.
    // vector<int> *adj;
    // adj = new vector<int>[v];

   public:
    Graph(int x) : v(x) {
        adj = new list<int>[v];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        // adj[v].push_back(u); // directed graph
    }

    bool isCyclic() {
        vector<bool> visited(v, false);
        vector<bool> stacked(v, false);
        int source = 0;

        return hasBackEdge(source, visited, stacked);
    }

    // check if any back edge (node -> ancestor node) exists in graph
    bool hasBackEdge(int node, vector<bool> &visited, vector<bool> &stacked) {
        visited[node] = true;
        stacked[node] = true;

        for (const auto &i : adj[node]) {
            if (!visited[i]) {
                return hasBackEdge(i, visited, stacked);
            } else if (stacked[i]) {
                // meaning there is an edge from this node to ancestor node
                printf("Edge (%d, %d) is back edge \n", node, i);
                return true;
            }
        }

        // remove node from stack as his path is searched
        stacked[node] = false;
        return false;
    }

    void print() {
        for (int i = 0; i < v; ++i) {
            cout << i << " --> ";
            for (auto j : adj[i]) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    // g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    // g.printGraph();

    if (g.isCyclic()) {
        cout << "Graph contains cycle" << endl;
        return 1;
    }

    cout << "Graph doesn't contain cycle" << endl;
    return 0;
}
