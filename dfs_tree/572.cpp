#include "utils.cpp"
#include <queue>


bool checkSame(TreeNode* node1, TreeNode* node2){ // can not be nullptr both
    if (node1 == nullptr && node2 == nullptr){
        return true;
    }
    if ((node1 == nullptr && node2 != nullptr) || (node1 != nullptr && node2 == nullptr)){
        return false;
    }

    if (node1 -> val != node2 -> val){
        return false;
    }
    bool res = true;
    res &= checkSame(node1->left, node2->left);
    res &= checkSame(node1->right, node2->right);
    return res;
}

bool dfs(TreeNode* root, TreeNode* subRoot){ //root is not nullptr

    cout << root -> val << " " << subRoot -> val << endl;
    cout << checkSame(root, subRoot) << endl;
    if (checkSame(root, subRoot)){
        return true;
    }
    bool res = false;
    if (root->left != nullptr){
        res |= dfs(root->left, subRoot);
    }
    if (root -> right != nullptr ){
        res |= dfs(root->right, subRoot);
    }
    return res;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (subRoot == nullptr){
        return true;
    }
    if (root == nullptr){
        return false;
    }
    return dfs(root, subRoot);
}

int main(){
    vector<int> data_1 = {3,4,5,1,2};
    TreeNode* node_1 = buildTree(data_1);

    vector<int> data_2 = {4,1,2};
    TreeNode* node_2 = buildTree(data_2);

    cout << isSubtree(node_1, node_2) << endl;
}