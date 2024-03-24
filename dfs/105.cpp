#include "utils.cpp"


TreeNode* buildTreeHelp(vector<int>& preorder, int i, int j, vector<int>& inorder, int m, int n){
    cout << i << " " << j << " " << m << "  " << n << endl;
    if (i > j || m > n){
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[i]);
    int k;
    for (k = m; k <= n; k++){
        if (inorder[k] == preorder[i]){
            break;
        }
    }
    root->left = buildTreeHelp(preorder, i + 1, i + k - m, inorder, m, k-1);
    root->right = buildTreeHelp(preorder, i + k - m + 1, j, inorder, k+1, n);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root = buildTreeHelp(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    return root;
}

int main(){
    vector<int> data_1 = {3,9,20,15,7};
    vector<int> data_2 = {9,3,15,20,7};
    cout << buildTree(data_1, data_2)->right->right->val << endl;
}