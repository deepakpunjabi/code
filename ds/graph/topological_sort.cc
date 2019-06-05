#include <iostream>
#include <list>
#include <queue>
#include <stack>
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
        adj = new list<int>[x];
    }

    // we need directed acyclic graph for
    // topological sort
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    void process(int src, vector<bool> &visited, stack<int> &topology);
    void topologicalSort();
};

void Graph::process(int src, vector<bool> &visited, stack<int> &topology) {
    if (visited[src]) return;
    visited[src] = true;

    for (const auto &i : adj[src]) {
        process(i, visited, topology);
    }

    topology.push(src);
}

void Graph::topologicalSort() {
    vector<bool> visited(v, false);
    stack<int> topology;

    for (int i = v-1; i >= 0; --i) {
        process(i, visited, topology);
    }

    while (!topology.empty()) {
        cout << topology.top() << " --> ";
        topology.pop();
    }
    cout << endl;
}

int main() {
    Graph g(6);

    g.addEdge(5, 0);
    // g.addEdge(5, 1);

    g.addEdge(4, 3);
    g.addEdge(2, 0);
    g.addEdge(3, 0);
    g.addEdge(1, 5);

    g.topologicalSort();

    return 0;
}
