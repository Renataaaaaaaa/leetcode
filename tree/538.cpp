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


TreeNode* convertBST(TreeNode* root) {
    stack<TreeNode* >nodes;
    TreeNode* cur = root;
    int sum = 0;
    while(cur != nullptr || nodes.size() != 0){
        // cout << "cur val" << cur->val << endl;
        while(cur != nullptr){
            nodes.push(cur);
            cur = cur->right;
        }
        cur = nodes.top();
        cout << cur->val << endl;

        cur->val = sum + cur->val;
        sum = cur->val;
        cout << sum << endl;
        nodes.pop();

        // nodes.top()->val = nodes.top()->val + sum;
        // sum = nodes.top()->val;
        cur = cur->left;

    }
    return root;
}