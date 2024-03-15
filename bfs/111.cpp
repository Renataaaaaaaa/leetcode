#include <vector>
#include <iostream>
#include <queue>
#include "utils.cpp"
using namespace std;


int minDepth(TreeNode* root) {
    if (root == nullptr){
        return 0;
    }
    queue<TreeNode* > queue_1;
    queue_1.push(root);
    int level = 1;
    int size = 0;
    while(!queue_1.empty()){
        size = queue_1.size();
        for (int i = 0; i < size; i++){
            TreeNode* node = queue_1.front();
            if (node->left == nullptr && node->right == nullptr){
                return level;
            }
            if (node->left != nullptr){
                queue_1.push(node->left);
            }
            if (node->right != nullptr){
                queue_1.push(node->right);
            }
            queue_1.pop();
        }
        level++;
    }
    return level;
}

int main(){
    vector<int> data = {2,-100,3,-100,4,-100,5,-100,6};
    cout << minDepth(buildTree(data)) << endl;;

}