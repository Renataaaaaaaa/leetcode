#include "utils.cpp"

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr){
        return nullptr;
    }
    if (key == root->val){
        //右子树的最左，的左未，root的左
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if (right == nullptr){
            return left;
        }else{
            TreeNode* right_move = root->right;
            while(right_move != nullptr && right_move->left != nullptr){
                right_move = right_move->left;
            }

            right_move->left = left;
            return right;
        }


    }else if (key > root->val){
        root->right = deleteNode(root->right, key);
    }else if (key < root->val){
        root->left = deleteNode(root->left, key);
    }
    return root;
}
int main(){
    vector<int> nums = {5,3,6,2,4,-100,7};
    TreeNode* node = buildTree(nums);
    cout << deleteNode(node, 3)->left->left->val << endl;
}