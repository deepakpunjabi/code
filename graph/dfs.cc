#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
    int v;
    list<int>* adj;
    // can use vector as well.
    // vector<int> *adj;
    // adj = new vector<int>[v];

   public:
    Graph(int x) : v(x) {
        adj = new list<int>[x];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    void dfsNode(int node, vector<bool>& visited) {
        // this might happen due to looping over in dfs
        if (visited[node]) {
            return;
        }
        visited[node] = true;

        process(node);

        for (const auto& i : adj[node]) {
            if (!visited[i]) {
                cout << "exploring edge: " << node << " --> " << i << endl;
                dfsNode(i, visited);
            }
        }
    }

    void dfs() {
        vector<bool> visited(v, false);
        // this is needed for forest
        // otherwise your reach will be only till depth starting from src
        for (int i = 0; i < v; ++i) {
            cout << "running dfs from: " << i << endl;
            dfsNode(i, visited);
        }
    }

    void process(int node) {
        cout << "processing: " << node << endl;
    }
};

int main() {
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(4, 4);

    // this edge will not come in output
    // for that, we need to use dfs for connected components
    // via reversing the direction
    g.addEdge(6, 5);

    // g.bfs(0);
    // g.bfs(4);

    g.dfs();

    return 0;
}
