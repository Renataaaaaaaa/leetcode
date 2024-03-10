#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* increasingBSTHelp(TreeNode* node, TreeNode* new_root){
    if (node == nullptr){
        return nullptr;
    }
    cout << "node " << node->val << endl;
    TreeNode* new_root_return = nullptr;
    increasingBSTHelp(node->left, new_root);
    if (new_root == nullptr){
        new_root = new TreeNode(node->val);
        new_root_return = new_root;
        cout << new_root_return->val << endl;
    }else{
        new_root->right = new TreeNode(node->val);
        new_root = new_root->right;
        // root = new_root->right;
    }
    // cout << node->val << endl;
    increasingBSTHelp(node->right, new_root);
    cout << new_root_return->val << endl;
    return new_root_return;
    
}

TreeNode* increasingBST(TreeNode* root) {
    TreeNode* new_root = nullptr;
    new_root = increasingBSTHelp(root, new_root);
    cout << "39" << endl;
    // cout << new_root_return->right->right->val << endl;
    return new_root;
}