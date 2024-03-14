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
    int char_num = 0;
    int path_num = 0;
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

    void dfs(TreeNodee* root_cur, int res){

        res = res + 1;
        int path_num = 0;
        for (int i = 0; i<26; i++){
            if (root_cur->children[i] != nullptr){
                dfs(root_cur->children[i], res);
                path_num++;
            }
        }
        if (path_num == 0){
            cout << "leaf res " << res << endl;
            char_num += res;
        }

    }

};
class Solution {
public:
int minimumLengthEncoding(vector<string>& words) {
    Trie trie;
    int res = 0;
    reverse(words[0].begin(), words[0].end());
    trie.insert(words[0]);
    for (vector<string>::size_type i = 1; i<words.size(); i++){
        reverse(words[i].begin(), words[i].end());
        trie.insert(words[i]);
    }
    trie.dfs(trie.root, 0);
    cout << "char num " << trie.char_num << endl;
    return trie.char_num;
}
};