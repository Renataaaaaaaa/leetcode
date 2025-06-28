#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
#include "utils.cpp"
using namespace std;

int res = 0;
void dfs(TreeNode* root, int cur_res){
    cur_res = cur_res + root->val;
    if (root->left == nullptr && root->right == nullptr){
        res += cur_res;
        return;
    }
    
    dfs(root->left, cur_res * 10);
    dfs(root->right, cur_res * 10);
}

int sumNumbers(TreeNode* root) {
    dfs(root, 0);
    return res;
}

int main(){
    vector<int> data = {4,9,0,5,1};
    cout << sumNumbers(buildTree(data)) << endl;
}