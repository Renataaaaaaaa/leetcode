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

    void dfs(TreeNodee* root_cur, int res){ //ATTENTION: 用dfs获取图中所有点的个数

        res = res + 1;
        bool leaf = true;
        for (int i = 0; i < 26; i++){
            if (root_cur->children[i] != nullptr){
                dfs(root_cur->children[i], res);
                leaf = false;
            }
        }
        if (leaf){
            char_num += res;
        }

    }

};

int minimumLengthEncoding(vector<string>& words) {
    Trie trie;
    int res = 0;
    for (vector<string>::size_type i = 0; i<words.size(); i++){
        reverse(words[i].begin(), words[i].end());
        trie.insert(words[i]);
    }
    trie.dfs(trie.root, 0);
    cout << "char num " << trie.char_num << endl;
    return trie.char_num;
}

int main(){
    vector<string> words = {"time", "me", "bell"};
    cout << minimumLengthEncoding(words) << endl;
}