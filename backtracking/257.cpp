#include "utils.cpp"
#include <vector>
#include <iostream>
using namespace std;

void dfs(TreeNode* root, vector<string>& path,  string cur_path){
    if (root == nullptr){
        return;
    }
    cur_path += to_string(root->val);
    if (root->left == nullptr && root->right == nullptr) { 
        path.push_back(cur_path);                          
    } else {
        cur_path += "->";
        dfs(root->left, path, cur_path);
        dfs(root->right, path, cur_path);
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> path;
    string cur_path;
    dfs(root, path, cur_path);
    return path;
}

int main(){
    vector<int> data = {1,2,3,-100,5};
    TreeNode* node = buildTree(data);
    // cout << node->left->left->val << endl;


    for (auto item: binaryTreePaths(node)){
        cout << item << endl;
    }
}