#include "utils.cpp"



TreeNode* help(vector<int>& inorder, int i , int j , vector<int>& postorder, int m , int n){
    cout << i << " " << j << endl;
    cout << m << " " << n << endl;
    if (i > j || m > n){
        return nullptr;
    }
    TreeNode* root = new TreeNode(postorder[n]);
    int k;
    for(k = i; k <= j; k++){
        if (inorder[k] == postorder[n]){
            break;
        }
    }
    // k - i 个
    root->left = help(inorder, i, k-1, postorder, m, m + k - i - 1);
    root->right = help(inorder, k+1, j, postorder, m + k - i, n-1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    TreeNode* res = help(inorder, 0, inorder.size() - 1, postorder, 0 , postorder.size() - 1);
    return res;
}
int main(){
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* res = buildTree(inorder, postorder);
    cout << res->val << endl;
}   