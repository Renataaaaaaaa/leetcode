#include "utils.cpp"

bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
        return false;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return targetSum == root->val;
    }
    return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    
}

int main(){
    vector<int> data = {5,4,8,11,-100,13,4,7,2,-100,-100,-100,1};
    // vector<int> data = {1,2};
    TreeNode* root = buildTree(data);
    cout << hasPathSum(root, 22) << endl;
}