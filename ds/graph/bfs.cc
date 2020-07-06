/* 
    Time Complexity: O(V + E) - time taken to traverse every vertice and edge of the graph once
*/

#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
    int v;

    // can use vector as well.
    // vector<int> *adj;
    // adj = new vector<int>[v];
    list<int> *adj;

   public:
    Graph(int x) : v(x) {
        adj = new list<int>[v];
    }

    ~Graph() {
        delete adj;
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
            process(front);

            for (const auto &i : adj[front]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void process(int v) {
        cout << v << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(4, 4);

    g.bfs(0);
    // g.bfs(4);

    return 0;
}
