#include "utils.cpp"

TreeNode* help(vector<int>& nums, int i, int j){
    if (j < i){
        return nullptr;
    }
    int max_index;
    int max = INT32_MIN;
    for (int k = i; k <= j; k++){
        if (nums[k] > max){
            max_index = k;
            max = nums[k];
        }
    }
    TreeNode* root = new TreeNode(nums[max_index]);
    root->left = help(nums, i, max_index - 1);
    root->right = help(nums, max_index + 1, j);
    return root;
}
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    TreeNode* res = help(nums, 0, nums.size() - 1);
    return res;
}

int main(){
    vector<int> data = {3,2,1,6,0,5};
    cout << constructMaximumBinaryTree(data)->right->val << endl;
}