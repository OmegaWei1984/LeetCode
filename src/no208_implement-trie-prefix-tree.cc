#include <iostream>
#include <vector>

using namespace std;

class Trie {
public:
    Trie() {

    }
    
    void insert(string word) {

    }
    
    bool search(string word) {

    }
    
    bool startsWith(string prefix) {

    }
};

int main(void) {
    Trie trie;
    trie.insert("apple");
    trie.search("apple");   // 返回 True
    trie.search("app");     // 返回 False
    trie.startsWith("app"); // 返回 True
    trie.insert("app");
    trie.search("app");     // 返回 True

    return 0;
}