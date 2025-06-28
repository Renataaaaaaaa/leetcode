#include "utils.cpp"

unordered_map<long long, int> prefix;

int dfs(TreeNode *root, long long curr, int targetSum) {
    if (!root) {
        return 0;
    }

    int ret = 0;
    curr += root->val;
    if (prefix.count(curr - targetSum)) {
        ret = prefix[curr - targetSum];
    }

    prefix[curr]++;
    ret += dfs(root->left, curr, targetSum);
    ret += dfs(root->right, curr, targetSum);
    prefix[curr]--;

    return ret;
}

int pathSum(TreeNode* root, int targetSum) {
    prefix[0] = 1;
    return dfs(root, 0, targetSum);
}

int main(){
    vector<int> data = {10,5,-3,3,2,-100,11,3,-2,-100,1};
    cout << pathSum(buildTree(data), 8) << endl;
}