#include "utils.cpp"


//不唯一，左子树或右子树有一个是空的，就是一样的
//前序 跟 左子树 右子树
//后序 左子树 右子树 跟
TreeNode* help(vector<int>& preorder, int i , int j , vector<int>& postorder, int m , int n){
    if ( i > j || m > n){
        return nullptr;
    }
    if (i == j){
        return new TreeNode(preorder[i]);
    }
    TreeNode* root = new TreeNode(preorder[i]);
    int k;
    for(k = m; k <= n; k++){
        if (preorder[i+1] == postorder[k]){
            break;
        }
    }
    root->left = help(preorder, i + 1, i + (k - m + 1), postorder, m, k);
    root->right = help(preorder, i + (k - m + 1) + 1, j, postorder, k + 1, n-1);
    return root;
}
TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    TreeNode* res = help(preorder, 0, preorder.size() - 1, postorder, 0 , postorder.size() - 1);
    return res;
}
int main(){
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,1};
    // vector<int> preorder = {1};
    // vector<int> postorder = {1};
    TreeNode* res = constructFromPrePost(preorder, postorder);
    cout << res->val << endl;
}   