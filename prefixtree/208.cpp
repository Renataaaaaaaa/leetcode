#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

class TreeNodee{
    public:
        TreeNodee* children[26];
        bool isEnd = false;
    TreeNodee(){
        for (auto& child : children) {
            child = nullptr;
        }
    }
};

class Trie {
public:
    TreeNodee* root;
    Trie() {
        root = new TreeNodee();
    }
    
    void insert(string word) {
        TreeNodee* root_move = root;
        for(auto c: word){
            if (root_move->children[c - 'a'] == nullptr){
                root_move->children[c - 'a'] = new TreeNodee();
            }
            root_move = root_move->children[c - 'a'];
        }
        root_move->isEnd = true;
    }
    
    bool search(string word) {
        TreeNodee* root_move = root;
        for(auto c: word){
            if (root_move->children[c - 'a'] == nullptr){
                return false;
            }else{
                root_move = root_move->children[c - 'a'];
            }
        }
        return root_move->isEnd;
    }
    
    bool startsWith(string prefix) {
        TreeNodee* root_move = root;
        for(auto c: prefix){
            if (root_move->children[c - 'a'] == nullptr){
                return false;
            }else{
                root_move = root_move->children[c - 'a'];
            }
        }
        return true;
    }
};

int main(){
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl; 
    cout << trie.search("app") << endl;
    trie.insert("app");
    cout << trie.search("app") << endl;

}