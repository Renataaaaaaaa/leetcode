#include "utils.cpp"

#include <stack>

void inOrder(TreeNode* node){
    stack<TreeNode *> stack;
    while (node != nullptr || stack.size() > 0) {
        while (node != nullptr) {
            stack.push(node);
            node = node->left;
        }

        node = stack.top();
        cout << node->val << endl;
        stack.pop();
        node = node->right;
    }
    // return node->val;
}

int main(){
    vector<int> data = {1,2,3,4,5,6,7};
    TreeNode* node = buildTree(data);
    inOrder(node);
}