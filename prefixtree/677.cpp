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
        int value = 0;
    TreeNodee(){
        for (auto& child : children) {
            child = nullptr;
        }
    }
};


class MapSum {
public:
    TreeNodee* root = new TreeNodee();
    MapSum() {
        
    }
    

    void insert(string key, int val) {
        TreeNodee* root_move = root;
        for (auto c: key){
            if (root_move->children[c - 'a'] == nullptr){
                root_move->children[c - 'a'] = new TreeNodee();
            }
            root_move = root_move->children[c - 'a'];
        }
        root_move->isEnd = true;
        root_move->value = val;
    }

    TreeNodee* search(string prefix) {
        TreeNodee* root_move = root;
        for(auto c: prefix){
            if (root_move == nullptr || root_move->children[c - 'a'] == nullptr){
                return nullptr;
            }else{
                root_move = root_move->children[c - 'a'];
            }
        }
        return root_move;
    }

    int dfs(TreeNodee* root_cur){
        int res;
        if (root_cur->isEnd){
            res = root_cur->value;
        }else{
            res = 0;
        }
        for (int i = 0; i < 26; i++){
            if (root_cur->children[i] != nullptr){
                res += dfs(root_cur->children[i]);
            }
        }
        return res;
    }
    int sum(string prefix) {
        // TreeNode* root_move = root;
        TreeNodee* root_begin = search(prefix);
        if (root_begin == nullptr){
            return 0;
        }
        return dfs(root_begin);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
