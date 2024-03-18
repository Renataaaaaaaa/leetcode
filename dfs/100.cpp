#include "utils.cpp"


bool dfs(TreeNode* p, TreeNode* q){
    if (p == nullptr && q == nullptr){
        return true;
    }
    if ((p == nullptr && q!=nullptr) || (p != nullptr && q == nullptr)){
        return false;
    }
    if (p->val != q->val){
        return false;
    }
    if (!dfs(p->left, q->left)){
        return false;
    }
    if (!dfs(p->right, q->right)){
        return false;
    }
    return true;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    return dfs(p, q);
}

int main(){
    vector<int> data_1 = {1,2};
    vector<int> data_2 = {1,-100,2};
    TreeNode* p = buildTree(data_1);
    TreeNode* q = buildTree(data_2);
    cout << isSameTree(p, q) << endl;
}