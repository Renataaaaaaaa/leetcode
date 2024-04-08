#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include "utils.cpp"
using namespace std;


int findBottomLeftValue(TreeNode* root) {
    int res = 0;
    if (root == nullptr){
        return res;
    }
    queue<TreeNode* > nodes;
    nodes.push(root);
    res = root->val;
    while(nodes.size() != 0){
        int size = nodes.size();
        int cur_res = 0;
        bool first_one = true;
        for(int i = 0; i < size; i++){
            TreeNode* current = nodes.front();
            if (nodes.front()->left != nullptr){
                nodes.push(nodes.front()->left);
                if (first_one){
                    cur_res = nodes.front()->left->val;
                    first_one = false;
                }
            }
            if (nodes.front()->right != nullptr){
                nodes.push(nodes.front()->right);
                if (first_one){
                    cur_res = nodes.front()->right->val;
                    first_one = false;
                }
            }
            nodes.pop();
        }
        if (nodes.size() != 0){
            res = cur_res;
        }
        
    }
    return res;
}
int main(){
    vector<int> data = {1,2,3,4,-100,5,6,-100,-100,7};
    cout << findBottomLeftValue(buildTree(data)) << endl;
}