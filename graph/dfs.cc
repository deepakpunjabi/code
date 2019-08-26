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
        // adj[v].push_back(u);
    }

    void bfs(int s) {
        vector<bool> visited(v, false);
        queue<int> q;

        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            cout << front << endl;

            for (auto i : adj[front]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void dfs(int s, vector<bool> &visited) {
        visited[s] = true;
        cout << s << endl;

        for (auto i : adj[s]) {
            if (!visited[i]) {
                dfs(i, visited);
            }
        }
    }

    void dfsDriver(int s) {
        vector<bool> visited(v, false);
        dfs(s, visited);
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(4, 4);

    // g.bfs(0);
    // g.bfs(4);

    g.dfsDriver(0);

    return 0;
}
