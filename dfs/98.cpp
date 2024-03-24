#include "utils.cpp"
#include <stack>
bool isValidBST(TreeNode* root) {
    stack<TreeNode *> stack;
    bool first_one = true; //ATTENTION: 标识不要用数字
    int last_num = 0;
    while (root != nullptr || stack.size() > 0) {
        while (root != nullptr) {
            stack.push(root);
            root = root->left;
        }

        root = stack.top();
        if (!first_one && root->val <= last_num){
            return false;
        }else{
            last_num = root->val;
            first_one = false;
        }
        stack.pop();
        root = root->right;
    }
    return true;
    // return node->val;
}

int main(){
    vector<int> data = {5,1,4,-100,-100,3,6};
    cout << isValidBST(buildTree(data)) << endl;
}