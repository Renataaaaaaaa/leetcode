#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class BSTIterator {
public:
    stack<TreeNode* >nodes;
    TreeNode* curr;

    BSTIterator(TreeNode* root) {
        curr = root;
        while(curr!=nullptr){
            nodes.push(curr);
            curr = curr->left;
        }
        // curr = nodes.top();
        // cout << curr->val;
        // nodes.pop();
        // curr = curr->right;
    }
    
    int next() {
        while(curr != nullptr){
            nodes.push(curr);
            curr = curr->left;
        }
        curr = nodes.top();
        int res = curr->val;
        nodes.pop();
        curr = curr->right;
        return res;
    }
    
    bool hasNext() {
        if(curr == nullptr && nodes.size() == 0){
            return false;
        }
        return true;
    }
};