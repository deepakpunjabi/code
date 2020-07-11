
# Notes

- Use `container.clear()` in class destructor to free up memory.
- Focus on more software engineering type approach rather than competitive coding for interview.
- Use higher level abstractions like full, empty instead of relying on internal constructors like top or rear.
- Members and functions cannot have the same name, reason for this is in c/cpp everything can be addressed by pointer. So it cannot be known if `&front` is member `front` or function `front()`.
- Don't forget to write return inside if statements.

# switch

- Duplicate case values are not allowed.
- switches are fall through in cpp, need to add break after every case.

# vector

- vector has a range based construtor which can be used in various use cases. eg. converting string to vector character array `vector<char> vc(str.begin(), str.end())`
- initialize 2d vector as: `vector<vector<bool>> visited(rows, vector<bool>(cols, false))`

# map / unordered_map

- map: balanced binary search tree, unordered_map: hash table
- Time complexity for map operations is `O(logn)` while for unordered_map is `O(logn)` on average.
- Performance of the hash table depends on the hash function but on average it is constant for search, insert and delete.

- search: `m.find(elem) != m.end()`

# string

- use `stringstream` to tokenize(split) string, convert string to int, float, double, remove spaces from string, string to vector etc
- use `getline(stream, result, delimeter)` to get split(via delimeter) into result(1 at a time) eg. `while (getline(ss, num, ","))`

# queue

- while poping from queue, you can initilize `count` as `queue.size()` and pop till `count--` instead of using a `separator` node.
