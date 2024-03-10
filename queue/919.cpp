#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTInserter {
public:
    TreeNode* tree_root = nullptr;
    queue<TreeNode* > nodes;
    CBTInserter(TreeNode* root) {
        tree_root = root;
        nodes.push(tree_root);
    }
    
    int insert(int val) {
        // if (tree_root == nullptr){

        //     return 
        // }
        // queue<TreeNode* > nodes;
        // nodes.push(tree_root);
        while(nodes.front()->left != nullptr && nodes.front() ->right != nullptr){
            nodes.push(nodes.front()->left);
            nodes.push( nodes.front()->right);
            nodes.pop();
        }
        if (nodes.front()->left == nullptr){
            nodes.front()->left = new TreeNode(val);
        }else{
            nodes.front()->right = new TreeNode(val);
        }
        return nodes.front()->val;
    }
    
    TreeNode* get_root() {
        return tree_root;
    }
};