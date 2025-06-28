#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
#include "utils.cpp"
using namespace std;

int maxZigZag = 0;
pair<int, int> dfs(TreeNode* root){
    if (root == nullptr){
        return {0, 0};
    }
    if (root->left == nullptr && root->right == nullptr){
        return {1, 1};
    }
    pair<int, int> res_left = dfs(root->left);
    pair<int, int> res_right = dfs(root->right);
    // cout << root->val << " " << res_left.second + 1 << " " << res_right.first + 1 << endl;
    maxZigZag = max(maxZigZag, max(res_left.second + 1, res_right.first + 1));
    return make_pair(res_left.second + 1, res_right.first + 1);
}

int longestZigZag(TreeNode* root) {
    pair<int, int> res = dfs(root);
    return maxZigZag - 1;
}
int main(){
    vector<int> nodes = {1,-100,2,3,4,-100,-100,5,6,-100,7,-100,-100,-100,8};
    TreeNode* node = buildTree(nodes);
    cout << longestZigZag(node) << endl;
}