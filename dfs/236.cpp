#include "utils.cpp"


// vector<TreeNode* > res = {};
bool dfs(TreeNode* root, TreeNode* target, vector<TreeNode*>& path){ //ATTENTION: how to find the path from root to target
    if (root == nullptr){
        return false;
    }
    path.push_back(root);
    if (root->val == target->val){
        cout << root -> val << endl;
        return true;
    }

    if (dfs(root->left, target, path) || dfs(root->right, target, path)){
        return true;
    }
    path.pop_back();
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> p_path;
    vector<TreeNode*> q_path;
    dfs(root, p, p_path);
    dfs(root, q, q_path);
    int i = 0;
    while(i < p_path.size() && i < q_path.size() && p_path[i] == q_path[i]){
        i++;
    }
    return p_path[i-1];
}

int main(){
    TreeNode* node_1 = new TreeNode(1);
    TreeNode* node_2 = new TreeNode(2);
    TreeNode* node_3 = new TreeNode(3);
    node_1->left = node_2;
    node_1->right = node_3;
    cout << lowestCommonAncestor(node_1, node_2, node_3) -> val << endl;
}