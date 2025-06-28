#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
#include "utils.cpp"
using namespace std;

int good = 0;
void dfs(TreeNode* root, int max){
    if (root == nullptr){
        return;
    }
    if (root->val >= max){
        good++;
        max = root->val;
    }
    dfs(root->left, max);
    dfs(root->right, max);
}

int goodNodes(TreeNode* root) {
    if (root == nullptr){
        return 0;
    }
    dfs(root, root->val);
    return good;
}

int main(){
    vector<int> nodes = {2,-100,4,10,8,-100,-100,4};
    TreeNode* node = buildTree(nodes);
    cout << goodNodes(node) << endl;
}