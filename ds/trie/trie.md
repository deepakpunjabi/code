# Trie (Prefix Tree)

- A trie is a variant of an n-ary tree in which characters are stored at each node. 
- Each path down the tree may represent a word.
- The * nodes (sometimes called "null nodes") are often used to indicate complete words. eg. `MA`, `MAN*`, `MANY*`
- End of word can be achieved via a boolean property in nodes as well.
- Node can have `[0, ALPHABET_SIZE]` child nodes.
- Often used for prefix lookups(useful for predictive searching).
- Prefix lookup takes `O(k)` time where k is the lenght of lookup string. 
