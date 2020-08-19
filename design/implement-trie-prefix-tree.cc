/*
    Implement a trie with insert, search, and startsWith methods.

    Example:
    Trie trie = new Trie();

    trie.insert("apple");
    trie.search("apple");   // returns true
    trie.search("app");     // returns false
    trie.startsWith("app"); // returns true
    trie.insert("app");   
    trie.search("app");     // returns true

    Note:
    You may assume that all inputs are consist of lowercase letters a-z.
    All inputs are guaranteed to be non-empty strings.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
    Start with a dummy node.
    Keep adding nodes for each edges.
    Do not overwrite node if it already exists.
*/
class Trie {
    bool is_word;
    unordered_map<char, Trie *> children;

   public:
    /** Initialize your data structure here. */
    Trie() : is_word(false) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *old = this;
        Trie *neww;
        for (const auto &i : word) {
            auto it = old->children.find(i);
            if (it == old->children.end()) {
                neww = new Trie();
                old->children[i] = neww;
            } else {
                neww = it->second;
            }

            old = neww;
        }
        neww->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.empty()) return true;

        Trie *t = this;
        for (const auto &i : word) {
            auto it = t->children.find(i);
            if (it == t->children.end()) return false;
            t = it->second;
        }

        return t->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix.empty()) return true;

        Trie *t = this;
        for (const auto &i : prefix) {
            auto it = t->children.find(i);
            if (it == t->children.end()) return false;
            t = it->second;
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
