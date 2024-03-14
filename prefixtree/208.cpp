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
        cout << "insert" << endl;
        TreeNodee* root_move = root;
        for(auto c: word){
            bool find = false;
            if (root_move->children[c - 'a'] == nullptr){
                root_move->children[c - 'a'] = new TreeNodee();
            }
            root_move = root_move->children[c - 'a'];
        }
        cout << " 28" << endl;
        cout << (root_move == nullptr) << endl;
        root_move->isEnd = true;
        cout << " 30" << endl;
    }
    
    bool search(string word) {
        cout << "search" << endl;
        TreeNodee* root_move = root;
        for(auto c: word){
            if (root_move == nullptr || root_move->children[c - 'a'] == nullptr){
                return false;
            }else{
                root_move = root_move->children[c - 'a'];
            }
        }
        if (root_move->isEnd){
            return true;
        }else{
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        cout << "startsWith" << endl;
        TreeNodee* root_move = root;
        for(auto c: prefix){
            if (root_move == nullptr || root_move->children[c - 'a'] == nullptr){
                return false;
            }else{
                root_move = root_move->children[c - 'a'];
            }
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