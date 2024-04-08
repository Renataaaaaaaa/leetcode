#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include "utils.cpp"
using namespace std;


vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (root == nullptr){
        return res;
    }
    queue<TreeNode* > nodes;
    nodes.push(root);
    res.push_back(root->val);
    while(nodes.size() != 0){
        int size = nodes.size();
        int rightMost = 0;
        for(int i = 0; i < size; i++){
            TreeNode* current = nodes.front();
            if (nodes.front()->left != nullptr){
                nodes.push(nodes.front()->left);
                rightMost = nodes.front()->left->val;
            }
            if (nodes.front()->right != nullptr){
                nodes.push(nodes.front()->right);
                rightMost = nodes.front()->right->val;
            }
            nodes.pop();
        }
        if (nodes.size() != 0){
            res.push_back(rightMost);
        }
    }
    return res;
}

int main(){
    vector<int> data = {1,2,3,-100,5,-100,4};
    for(auto item: rightSideView(buildTree(data))){
        cout << item << endl;
    }
}