#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#include "utils.cpp"

unordered_map<TreeNode*, int> map;
int getDp(TreeNode* node){
    if (node == nullptr){
        return 0;
    }
    return map[node];
}

void dfs(TreeNode* node){

    if (node == nullptr){
        return;
    }
    dfs(node->left);
    dfs(node->right);


    int option1 = getDp(node->left) + getDp(node->right);
    int option2 = node->val;
    if (node->left != nullptr){
        option2 += getDp(node->left->left) + getDp(node->left->right);
    }
    if (node->right != nullptr){
        option2 += getDp(node->right->left) + getDp(node->right->right);
    }
    map[node] = max(option1, option2);
}
//后序遍历
int rob(TreeNode* root) {
    dfs(root);
    return map[root];
}
int main(){
    vector<int> nums = {3, 2, 3, -100, 3, -100, 1};
    // vector<int> nums = { 4,2,-100,1,3};
    TreeNode* node = buildTree(nums);
    cout << rob(node) << endl;
}