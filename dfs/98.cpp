#include "utils.cpp"
#include <stack>


bool help(TreeNode* root, TreeNode* maxnum, TreeNode* minnum){
    if (root == nullptr){
        return true;
    }
    if ((maxnum != nullptr && root->val >= maxnum->val) || (minnum != nullptr && root->val <= minnum->val)){
        return false;
    }
    if (root->left != nullptr && root->val <= root->left->val){
        return false;
    }
    if (root->right != nullptr && root->val >= root->right->val){
        return false;
    }
    return help(root->left, root, minnum) && help(root->right, maxnum, root);
}

bool isValidBST(TreeNode* root) {
   return help(root, nullptr, nullptr);
}

int main(){
    // vector<int> data = {5,1,4,-100,-100,3,6};
    vector<int> data = {2,1,3};
    cout << isValidBST(buildTree(data)) << endl;
}