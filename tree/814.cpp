#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include "utils.cpp"
using namespace std;

//后序遍历
TreeNode* dfs(TreeNode* root){
    if (root == nullptr){
        return nullptr;
    }
    root->left = dfs(root->left);
    root->right = dfs(root->right);
    if (root->left == nullptr && root->right == nullptr && root->val == 0){
        return nullptr;
    }
    return root;

}
TreeNode* pruneTree(TreeNode* root){
    dfs(root);
    return root;
}

int main(){
    vector<int> data = {0,-100,0,0,0};
    cout << pruneTree(buildTree(data))->right->left->val << endl;
}