#include "utils.cpp"
#include <queue>



void dfs(TreeNode* root, vector<string>& path,  string cur_path){ //ATTENTION: 不一定用引用
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