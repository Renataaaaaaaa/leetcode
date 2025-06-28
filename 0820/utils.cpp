#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//{1,2,3,4,5,6,7}
TreeNode* buildTree(vector<int>& data){
    if (data.empty()) return nullptr;
    
    TreeNode* root = new TreeNode(data[0]); // 创建根节点
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1; // 从数组的第二个元素开始
    while (i < data.size()) {
        TreeNode* parent = q.front();
        q.pop(); // 移除已经处理过的父节点
        
        if (data[i] == -100){
            parent->left = nullptr;
            i++;
        }else if (i < data.size()) {
            parent->left = new TreeNode(data[i++]);
            q.push(parent->left);
        }
        if (data[i] == -100){
            parent->right = nullptr;
            i++;
        }else if (i < data.size()) {
            parent->right = new TreeNode(data[i++]);
            q.push(parent->right);
        }
    }
    
    return root;
}