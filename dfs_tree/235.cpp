#include "utils.cpp"


void walk(TreeNode* root, TreeNode* target, vector<TreeNode*>& path){
    while(root != nullptr){
        path.push_back(root);
        if (root->val == target->val){
            return;
        }
        if (root->val < target->val){
            root = root->right;
        }else{
            root = root->left;
        }
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> p_path;
    vector<TreeNode*> q_path;
    walk(root, p, p_path);
    walk(root, q, q_path);
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
    node_2->left = node_1;
    node_2->right = node_3;
    cout << lowestCommonAncestor(node_2, node_1, node_3) -> val << endl;
}