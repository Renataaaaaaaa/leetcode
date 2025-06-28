#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <stack>
#include <set>
using namespace std;   

struct TreeNodee {
    string word;
    unordered_map<char,TreeNodee *> children;
    TreeNodee() {
        this->word = "";
    }   
};

class Solution {
public:
    void insertTrie(TreeNodee * root,const string & word) {
        TreeNodee * node = root;
        for (auto c : word){
            if (!node->children.count(c)) {
                node->children[c] = new TreeNodee();
            }
            node = node->children[c];
        }
        node->word = word;
    }


    // int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> dirs={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& board, int i, int j, TreeNodee* root, set<string>& res){
        char ch = board[i][j];        
        if (!root->children.count(ch)) {
            return;
        }
        root = root->children[ch];
        
        if (root->word.size() > 0){
            res.insert(root->word);
            root->word= ""; //ATTENTION
        }
        board[i][j] = '#';
        for (int k = 0; k < 4; ++k){
            int i_n = i + dirs[k][0];
            int j_n = j + dirs[k][1];
            if (i_n >= 0 && j_n >= 0 && i_n < board.size() && j_n < board[0].size()){
                if (board[i_n][j_n] != '#'){
                    dfs(board, i_n, j_n, root, res);
                }
                
            }
        }
        board[i][j] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TreeNodee * root = new TreeNodee();
        for(auto &str: words){
            insertTrie(root, str);
        }
        set<string> res;
        for(int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                dfs(board, i, j, root, res);
            }
        }
        vector<string> res_vec;
        for (auto &item: res){
            res_vec.push_back(item);
        }
        return res_vec;
    }
};

int main(){
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain", "oat"};
    for (auto str : findWords(board, words)){
        cout << str << endl;
    }
}