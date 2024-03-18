#include "utils.cpp"




bool dfs(TreeNode* root, int targetSum){
    if (root -> left == nullptr && root -> right == nullptr){ //leaf
        if (root -> val == targetSum){
            return true;
        }else{
            return false;
        }
    }
    int res = false;
    if (root -> left != nullptr){
        res |= dfs(root->left, targetSum - root->val);
    }
    if (root -> right != nullptr){
        res |= dfs(root->right, targetSum - root->val);
    }
    
    return res;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr){
        return false;
    }
    return dfs(root, targetSum);
}

int main(){
    vector<int> data = {5,4,8,11,-100,13,4,7,2,-100,-100,-100,1};
    // vector<int> data = {1,2};
    TreeNode* root = buildTree(data);
    cout << hasPathSum(root, 22) << endl;
}