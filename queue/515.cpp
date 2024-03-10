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
struct TreeNodeLevel {
    TreeNode* node;
    int level = 0; 
    TreeNodeLevel(TreeNode* node, int level): node(node), level(level) {}
};

vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    if (root == nullptr){
        return res;
    }
    queue<TreeNodeLevel* > nodes;
    nodes.push(new TreeNodeLevel(root, 1));

    int currentMax = root->val;
    int currentLevel = 1;
    while(nodes.size() != 0){
        if (nodes.front()->node->left != nullptr){
            nodes.push(new TreeNodeLevel(nodes.front()->node -> left, nodes.front()->level + 1));
        }
        if (nodes.front()->node-> right != nullptr){
            nodes.push(new TreeNodeLevel(nodes.front()->node -> right, nodes.front()->level + 1));
        }
        if (nodes.front() -> level > currentLevel){
            res.push_back(currentMax);
            currentMax = nodes.front() -> node -> val;
            currentLevel = nodes.front() -> level;
        }else{
            currentMax = max(nodes.front()->node->val, currentMax);
        }
        nodes.pop();
    }
    res.push_back(currentMax);
    return res;

}