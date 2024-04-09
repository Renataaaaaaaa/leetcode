#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include "utils.cpp"
using namespace std;

//中序

void increasingBSTHelp(TreeNode* node, vector<int>& res){
    if (node == nullptr){
        return;
    }
    increasingBSTHelp(node->left, res);
    res.push_back(node->val);
    increasingBSTHelp(node->right, res);
}
    

TreeNode* increasingBST(TreeNode* root) {
    vector<int> res;
    increasingBSTHelp(root, res);
    TreeNode dummy(0);
    TreeNode* move = &dummy;
    for (auto item: res){
        TreeNode* tmp = new TreeNode(item);
        move->right = tmp;
        move = move->right;
    }
    return dummy.right;
}

int main(){
    vector<int> data = {5,1,7};
    cout << increasingBST(buildTree(data))->right->val << endl;
}