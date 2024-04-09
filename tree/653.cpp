#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
#include "utils.cpp"
using namespace std;


void dfs(TreeNode* root, vector<int>& res){
    if (root == nullptr){
        return;
    }
    dfs(root->left, res);
    res.push_back(root->val);
    dfs(root->right, res);
}

bool findTarget(TreeNode* root, int k) {
    vector<int> res;
    stack<TreeNode* >nodes;
    TreeNode* cur = root;

    dfs(root, res);

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
int main(){
    vector<int> data = {5,3,6,2,4,-100,7};
    cout << findTarget(buildTree(data), 28) << endl;
}