
# Notes

- Use `container.clear()` in class destructor to free up memory.
- Focus on more software engineering type approach rather than competitive coding for interview.
- Use higher level abstractions like full, empty instead of relying on internal constructors like top or rear.
- Members and functions cannot have the same name, reason for this is in c/cpp everything can be addressed by pointer. So it cannot be known if `&front` is member `front` or function `front()`.

# switch

- Duplicate case values are not allowed.
- switches are fall through in cpp, need to add break after every case.

# map / unordered_map

- map: balanced binary search tree, unordered_map: hash table
- Time complexity for map operations is `O(logn)` while for unordered_map is `O(logn)` on average.
- Performance of the hash table depends on the hash function but on average it is constant for search, insert and delete.

- search: `m.find(elem) != m.end()`
