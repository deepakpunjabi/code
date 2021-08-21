# Code

## Run

`g++ --std=c++11 ds/queue/queue.cc && ./a.out && rm a.out`

## Notes

- Use `container.clear()` in class destructor to free up memory.
- Focus on more software engineering type approach rather than competitive coding for interview.
- Use higher level abstractions like full, empty instead of relying on internal constructors like top or rear.
- Members and functions cannot have the same name, reason for this is in c/cpp everything can be addressed by pointer. So it cannot be known if `&front` is member `front` or function `front()`.
- Don't forget to write return inside if statements.
- Usually notes like distinct elements, non-decreasing input etc are hint to specialize your solution based on input needs. [plus-one.cc](ds/array/plus-one.cc) is one such great example.
- `isupper()` returns value different from zero **(not 1)** if indeed c is an uppercase alphabetic letter. Zero (i.e., false) otherwise.

### switch

- Duplicate case values are not allowed.
- switches are fall through in cpp, need to add break after every case. Once a case condition is true, all cases after it are also true if `break` is not applied.

### vector

- vector has a range based construtor which can be used in various use cases. eg. converting string to vector character array `vector<char> vc(str.begin(), str.end())`
- initialize 2d vector as: `vector<vector<bool>> visited(rows, vector<bool>(cols, false))`

### map / unordered_map

- map: balanced binary search tree, unordered_map: hash table
- Time complexity for map operations is `O(logn)` while for unordered_map is `O(1)` on average.
- Performance of the hash table depends on the hash function but on average it is constant for search, insert and delete.

- search: `m.find(elem) != m.end()`

### string

- use `stringstream` to tokenize(split) string, convert string to int, float, double, remove spaces from string, string to vector etc
- use `getline(stream, result, delimeter)` to get split(via delimeter) into result(1 at a time) eg. `while (getline(ss, num, ","))`

### queue

- while poping from queue, you can initilize `count` as `queue.size()` and pop till `count--` instead of using a `separator` node.

## Array

- Arrays can have index starting from 0,1 or n based on usecase.
- Metrics usually requires lot of looping, better to save `#rows` and `#cols`
 in separate variables.

### Lambda Sort 2D vector

ie. `vector<vector<int>>`

```cpp
    [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }
```

```cpp
sort(grid.begin(), grid(end), 
    [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    });
)
```

## Backtracking

1. Define a termination conditions.
2. Loop through range of possibilities.
3. Pass a common state between function calls.
4. Reset state when a possibility doesn't work out.

## DFS

```cpp
void doWork() {
    define result
    do dfs recursion
    return result
}

void recurse(input data, result reference) {
    base conditions for breaking recursion and/or updating result

    mark youself / do work with current node

    recurse again
}
```

### Problems

- Find Minumum Spanning Tree
- Cycle Detection
- Check path exists between 2 nodes
- Topological Sorting
- Bipratite Graph (2 Coloring Problem)
- Strongly Connected Components
- Maze(2D Matrix) Problems

## Bit Manipulation

- Get LSB (least significant bit): 1. check `if (n % 2 == 0)` for even or 2. check `if (n & 1)` for odd
- Memoization could become more advantageous when dealing with the input of long bit stream. Eg. reversing an arbitary length bit stream. Here you can store each `byte->reversed` as cache.
- The left shift and right shift operators should not be used for negative numbers.

## [Bit Hacks](http://graphics.stanford.edu/~seander/bithacks.html)

- Reverse a byte

    ```python
    def reverseByte(byte):
        return (byte * 0x0202020202 & 0x010884422010) % 1023
    ```

- Reverse a number bit by bit

    ```cpp
    for (i = 0; i < NO_OF_BITS; i++) {
        temp = (num & (1 << i));
        if(temp)
            // set size-ith bit via OR if ith bit is set in original string
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }
    ```

## Binary Heap

- BHeap is a complete binary tree + each node is smaller than it's children.
- Root is the minimum element in the tree.
- 2 main operations: 1. Insert 2. Extract Min

### Insert

- Always at the end, rightmost position. This maintains it complete binary tree property.
- Fix the order of tree by bubbling up inserted element until required.
- Takes `O(logn)` time.

### Extract Minimum Element

- Read the root, get the minimum.
- Swap root with last element, decrease the size of heap by 1.
- Bubble down root until required.
- Takes `O(logn)` time.

## Tree

---

- Tree need not be a binary tree or binary search tree.
- For BST(with duplicate values): `left nodes <= root < right nodes` order property is maintained
- Complete Binary tree is where every level of the tree is filled(left to right), except for perhaps the last level.
- Full binary tree is where every node has 0/2 child, no node has 1 child. No left->right order is required.
- Perfect binary tree = full + complete + all leaf nodes are at same level. ie. tree has 2^L-1 nodes.
- Tree is a **connected** graph without cycles.

### Binary tree traversal

- inorder travelsal gives you all nodes in ascending order

## Trie (Prefix Tree)

- A trie is a variant of an n-ary tree in which characters are stored at each node. 
- Each path down the tree may represent a word.
- The * nodes (sometimes called "null nodes") are often used to indicate complete words. eg. `MA`, `MAN*`, `MANY*`
- End of word can be achieved via a boolean property in nodes as well.
- Node can have `[0, ALPHABET_SIZE]` child nodes.
- Often used for prefix lookups(useful for predictive searching).
- Prefix lookup takes `O(k)` time where k is the lenght of lookup string.

## Queue

- Follows FIFO: first in last out, eg. line of people waiting for their order to be served
- front: start of the queue
- rear: end of the queue
- enqueue: insert into the queue
- dequeue: delete from the queue
- `q.pop()` does not return front element, you need to explicitly call `q.front()`

### Types of Queue

- single ended queue: insert at back, delete from front
- double ended queue: insert/delete from front/back, can do rear+1 or rear-1 based on operation
- circular queue: use: reutilize deleted element space, need to keep `count/size` to implement `isEmpty()` and `isFull`

### Example Problems

- rotate a string by n
- invert a binary tree iteratively

## Graph

- Collection of nodes with edges between **(some of)** them.
- Directed vs Undirected
- `Graph = [] subgraphs`
- If there is a path between all nodes than it's a **connected graph**.
- Cyclic vs Acyclic graph
- Adjacency List vs Adjacency Matrices
- While using certain graph algorithms, you must ensure that each vertex of the graph is visited exactly once. This is specially true for graph containing cycles. To do this you can mark the node by having a boolean field in node or by keeping a separated visited array of vertices, latter being the simpler approach.

### Graph Traversal

- DFS vs BFS
- DFS is often preferred if we want to visit every node in the graph.
- If we want to find the shortest path (or just any path) between two nodes, BFS is generally better.
- Tree traversals are a form of DFS.

## Sorting

- Quickselect is a textbook algorthm typically used to solve the problems "find kth something": kth smallest, kth largest, kth most frequent, kth less frequent, etc.

## Linked List

---

- As linked list is connected via pointers, you don't need to traverse whole ll to update or delete a node.
