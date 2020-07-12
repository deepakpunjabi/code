# Graph

- Collection of nodes with edges between **(some of)** them.
- Directed vs Undirected
- `Graph = [] subgraphs`
- If there is a path between all nodes than it's a **connected graph**.
- Cyclic vs Acyclic graph
- Adjacency List vs Adjacency Matrices

## Graph Traversal

- DFS vs BFS
- DFS is often preferred if we want to visit every node in the graph.
- If we want to find the shortest path (or just any path) between two nodes, BFS is generally better.
- Tree traversals are a form of DFS.

## Notes

- While using certain graph algorithms, you must ensure that each vertex of the graph is visited exactly once. This is specially true for graph containing cycles. To do this you can mark the node by having a boolean field in node or by keeping a separated visited array of vertices, latter being the simpler approach.
