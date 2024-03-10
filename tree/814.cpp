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

TreeNode* pruneTree(TreeNode* root) {
    stack<TreeNode* > nodes;
    TreeNode* cur = root;
    TreeNode* prev = nullptr;
    while (cur != nullptr || nodes.size() != 0){
        while (cur != nullptr){ //bottom
            // cout << cur->val << endl;
            nodes.push(cur); //middle
            cur = cur->left;
        }
        cur = nodes.top(); //middle
        if (cur->right != nullptr && cur->right != prev){
            cur = cur->right;
        }else{
            TreeNode* tmp = nodes.top();
            nodes.pop();
            if (tmp->val == 0 && tmp->left == nullptr && tmp->right == nullptr){
                if (tmp == root){
                    return nullptr;
                }else if (tmp == nodes.top()->left){
                    nodes.top()->left = nullptr;
                }else{
                    nodes.top()->right = nullptr;
                }
            }
            prev = cur;
            cur = nullptr; //have cout middle
        }
    }
    cout << (root == nullptr) << endl;
    return root;

}