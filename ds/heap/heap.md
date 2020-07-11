# Binary Heap

- BHeap is a complete binary tree + each node is smaller than it's children.
- Root is the minimum element in the tree.
- 2 main operations: 1. Insert 2. Extract Min

## Insert

- Always at the end, rightmost position. This maintains it complete binary tree property.
- Fix the order of tree by bubbling up inserted element until required.
- Takes `O(logn)` time.

## Extract Minimum Element

- Read the root, get the minimum.
- Swap root with last element, decrease the size of heap by 1.
- Bubble down root until required.
- Takes `O(logn)` time.
