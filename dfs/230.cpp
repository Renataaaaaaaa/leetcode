#include "utils.cpp"
#include <stack>

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode *> stack;
    
    while (root != nullptr || stack.size() > 0) {
        while (root != nullptr) {
            stack.push(root);
            root = root->left;
        }

        root = stack.top();
        k--;
        if (k == 0){
            return root->val;
        }
        stack.pop();
        root = root->right;
    }
}

int main(){
    vector<int> data = {5,3,6,2,4,-100,-100,1};
    cout << kthSmallest(buildTree(data), 3) << endl;
}