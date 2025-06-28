#include "utils.cpp"


int dfs(TreeNode* root){
    if (root -> left == nullptr && root -> right == nullptr){
        return 1;
    }
    int left_depth = 0, right_depth = 0;
    if (root -> left != nullptr){
        left_depth = dfs(root->left);
    }
    if (root -> right != nullptr){
        right_depth = dfs(root->right);
    }
    return 1 + max(left_depth, right_depth);
}

int maxDepth(TreeNode* root) {
    if (root == nullptr){
            return 0;
    }
    return dfs(root);
}

int main(){
    // vector<int> data = {3,9,20,-100,-100,15,7};
    vector<int> data = {1,2,3,4,5};
    TreeNode* root = buildTree(data);
    cout << maxDepth(root) << endl;
}