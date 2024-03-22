#include "utils.cpp"


void dfs(TreeNode* root, vector<vector<int>> & paths, vector<int> path, int left){
    path.push_back(root->val);

    if (root ->left == nullptr && root->right == nullptr){
        if (left == root->val){
            paths.push_back(path);
        }
        return;
    }
    if (root -> left != nullptr){
        dfs(root->left, paths, path, left - root->val);
    }
    if (root -> right != nullptr){
        dfs(root->right, paths, path, left - root->val);
    }
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> paths;
    vector<int> path;
    dfs(root, paths, path, targetSum);
    return paths;
}

int main(){
    vector<int> data = {5,4,8,11,-100 ,13,4,7,2,-100,-100,5,1};
    TreeNode* node = buildTree(data);
    for (auto s: pathSum(node, 22)){
        for (auto item: s){
            cout << item << " ";
        }
        cout << endl;
    }
}