#include "utils.cpp"
#include <queue>


TreeNode* dfs(TreeNode* root1, TreeNode* root2){ //at least one of them is not nullptr
    
    if (root1 == nullptr){ //ATTENTION: interesting
        return root2;
    }
    if (root2 == nullptr){
        return root1;
    }
    
    TreeNode* res = new TreeNode(root1->val + root2->val);


    res->left = dfs(root1->left, root2->left);
    res->right = dfs(root1->right, root2->right);

    return res;
}
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr){
        return nullptr;
    }
    TreeNode* res = dfs(root1, root2);

    return res;
}

int main(){
    vector<int> data = {1,3,2,5};
    // vector<int> data = {1,2,3};
    // vector<int> data_2 = {1,-100,3};
    TreeNode* node = buildTree(data);
    vector<int> data_2 = {2,1,3,-100,4,-100,7};
    TreeNode* node_2 = buildTree(data_2);

    cout << mergeTrees(node, node_2)->right->val << endl;
}