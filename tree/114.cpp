#include "utils.cpp"

void flatten(TreeNode* root) {

    if (root == nullptr){
        return;
    }
    flatten(root->left);
    flatten(root->right);

    TreeNode* left = root->left;
    TreeNode* right = root->right;
    while(left != nullptr && left->right != nullptr){
        left = left->right;
    }
    if (left != nullptr){
        left->right = right;
        root->right = root->left;
        root->left = nullptr;
    }
}
int main(){
    vector<int> nodes = {1,2,5,3,4,-100,6};
    // vector<int> nodes = {1,-100,2};
    TreeNode* node = buildTree(nodes);
    flatten(node);
    while(node != nullptr){
        cout << node->val << endl;
        node = node->right;
    }
}