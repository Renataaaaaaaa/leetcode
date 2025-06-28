#include "utils.cpp"
#include <stack>

int res = 0;
void help(TreeNode* root, int k, int& rank){
    if (root == nullptr){
        return;
    }
    help(root->left, k ,rank);
    rank++;
    if (rank == k){
        res = root->val;
        return;
    }
    help(root->right, k, rank);
}
int kthSmallest(TreeNode* root, int k) {
    int rank = 0;
    help(root, k, rank);
    return res;
}

int main(){
    vector<int> data = {5,3,6,2,4,-100,-100,1};
    cout << kthSmallest(buildTree(data), 3) << endl;
}