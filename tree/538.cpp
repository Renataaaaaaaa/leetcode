#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
#include "utils.cpp"
using namespace std;

//中序，反向的

void dfs(TreeNode* root, int& num){
    if (root == nullptr){
        return;
    }
    dfs(root->right, num);
    num += root->val;
    root->val = num;
    dfs(root->left, num);
}


TreeNode* convertBST(TreeNode* root) {
    int num = 0;
    dfs(root, num);
    return root;
}
int main(){
    vector<int> data = {4,1,6,0,2,5,7,-100,-100,-100,3,-100,-100,-100,8};
    cout << convertBST(buildTree(data))->val << endl;
}