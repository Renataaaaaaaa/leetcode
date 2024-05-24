#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxPathSumHelp(TreeNode* root, int & maxSum){
    if (root == nullptr){
        return 0;
    }
    int left_sum = maxPathSumHelp(root->left, maxSum); //return must >= 0
    int right_sum = maxPathSumHelp(root->right, maxSum);
    int sum = root->val + left_sum + right_sum;
    maxSum = max(maxSum, sum);
    if (sum > 0){ //ATTENTION: ??? 不应该是半支吗
        if (left_sum > right_sum){
            return root->val + left_sum;
        }else{
            return root->val + right_sum;
        }
    }else{
        return 0;
    }
}

int maxPathSum(TreeNode* root) {
    int maxSum = root->val;
    maxPathSumHelp(root, maxSum);
    return maxSum;
}