#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
#include "utils.cpp"
using namespace std;


void dfs(TreeNode* root, int& res, int& cur_res){
    cur_res = cur_res + root->val;
    if (root->left == nullptr && root->right == nullptr){
        res += cur_res;
        cout << cur_res << endl;
        return;
    }
    

    cur_res *= 10;
    dfs(root->left, res, cur_res);
    cur_res /= 10;

    cur_res *= 10;
    dfs(root->right, res, cur_res);
    cur_res /= 10;

}

int sumNumbers(TreeNode* root) {
    int res = 0;
    int cur_res = 0;
    dfs(root, res, cur_res);
    return res;
}

int main(){
    vector<int> data = {4,9,0,5,1};
    cout << sumNumbers(buildTree(data)) << endl;
}