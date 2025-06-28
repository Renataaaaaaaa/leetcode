#include "utils.cpp"
#include <queue>




TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr){
        return nullptr;
    }
    if (root->left != nullptr){
        invertTree(root->left);
    }
    if (root->right != nullptr){
        invertTree(root->right);
    }
    
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
}

int main(){
    vector<int> data_1 = {4,2,7,1,3,6,9};
    TreeNode* node_1 = buildTree(data_1);
    cout << invertTree(node_1) -> left-> left->val << endl;
}