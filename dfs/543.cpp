#include "utils.cpp"
#include <queue>



int max_length = 0;

int dfs(TreeNode* root){
    int left_length = 0, right_length = 0;
    if (root->left != nullptr){
        left_length = dfs(root->left);
    }
    if (root->right != nullptr){
        right_length = dfs(root->right);
    }
    max_length = max(max_length, left_length + right_length + 1);
    return max(left_length, right_length) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr){
        return 0;
    }
    dfs(root);
    return max_length - 1;
}

int main(){
    vector<int> data = {1,2};
    TreeNode* node = buildTree(data);
    cout << diameterOfBinaryTree(node) << endl;
}