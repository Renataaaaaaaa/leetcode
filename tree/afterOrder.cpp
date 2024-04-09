#include "utils.cpp"

void dfs(TreeNode* root){
    if (root == nullptr){
        return;
    }
    dfs(root->left);
    dfs(root->right);
    cout << root->val << endl;
}
void afterOrder(TreeNode* root){
    dfs(root);
}

int main(){
    vector<int> data = {1,2,3};
    afterOrder(buildTree(data));
}