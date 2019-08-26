#include <iostream>
#include <list>
#include <queue>
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

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool dfs(int src, int parent, vector<bool> &visited);
    bool isCyclic();
};

bool Graph::dfs(int src, int parent, vector<bool> &visited) {
    if (visited[src]) return false;

    visited[src] = true;
    // cout << "visiting: " << src << endl;
    // cout << s << endl;

    for (const auto &i : adj[src]) {
        // cout << "processing edge: " << src << " --> " << i << endl;
        if (i == parent) {
            continue;
        } else if (visited[i]) {
            cout << "loop found at " << src << " --> " << i << endl;
            return true;
        } else if (dfs(i, src, visited)) {
            return true;
        }
    }

    return false;
}

bool Graph::isCyclic() {
    vector<bool> visited(v, false);
    for (int i = 0; i < v; ++i) {
        // cout << "looping for: " << i << endl;
        if (dfs(i, -1, visited)) return true;
    }
    return false;
}

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    // g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // g.addEdge(4, 4);

    cout << g.isCyclic() << endl;

    return 0;
}
