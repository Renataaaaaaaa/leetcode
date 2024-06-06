#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include "utils.cpp"
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<int, int>, vector<TreeNode*>, pair_hash> mem;
// vector<TreeNode*> res;
vector<TreeNode*> help(int i, int j){
    if (i > j){
        return {nullptr};
    }
    if (i == j){
        return {new TreeNode(i)};
    }
    if (mem.find(make_pair(i, j)) != mem.end()){
        return mem[make_pair(i, j)];
    }
    vector<TreeNode *> res;
    for(int k = i; k <= j; k++){
        // TreeNode* root = new TreeNode(k);
        vector<TreeNode*> left_trees = help(i, k - 1);
        vector<TreeNode*> right_trees  =  help(k + 1, j);
        for(auto left: left_trees){
            for(auto right: right_trees){
                TreeNode* root = new TreeNode(k);
                root->left = left;
                root->right = right;
                res.push_back(root);
            }
        }
    }
    mem[make_pair(i, j)] = res;
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> res = help(1, n);
    return res;
}
// int numTrees(int n) {
//     for(int i = 0; i < n; i++){
//         nums.push_back(0);
//     }
//     int res = count(1, n);
//     return res;
// }

int main(){
    for(auto item: generateTrees(3)){
        cout << item->val << endl;
    }
}