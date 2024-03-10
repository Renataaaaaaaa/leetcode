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


bool findTarget(TreeNode* root, int k) {
    vector<int> res;
    stack<TreeNode* >nodes;
    TreeNode* cur = root;

    while(nodes.size() != 0 || cur != nullptr){
        while(cur != nullptr){
            nodes.push(cur);
            cur = cur->left;
        }
        cur = nodes.top();
        res.push_back(cur->val);
        nodes.pop();
        cur = cur->right;
    }

    int lo = 0;
    int hi = res.size() - 1;
    while(hi > lo){
        if (res[lo] + res[hi] == k){
            return true;
        }else if(res[lo] + res[hi] > k){
            hi--;
        }else{
            lo++;
        }
    }
    return false;
}