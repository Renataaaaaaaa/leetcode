#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include "utils.cpp"
using namespace std;


vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    if (root == nullptr){
        return res;
    }
    queue<TreeNode* > nodes;
    nodes.push(root);
    res.push_back(root->val);
    while(nodes.size() != 0){
        int size = nodes.size();
        int levelMax = INT32_MIN;
        for(int i = 0; i < size; i++){
            TreeNode* current = nodes.front();
            if (nodes.front()->left != nullptr){
                nodes.push(nodes.front()->left);
                levelMax = max(levelMax, nodes.front()->left->val);
            }
            if (nodes.front()->right != nullptr){
                nodes.push(nodes.front()->right);
                levelMax = max(levelMax, nodes.front()->right->val);
            }
            nodes.pop();
        }
        if (levelMax != INT32_MIN){
            res.push_back(levelMax);
        }
        
    }
    return res;
}

int main(){
    vector<int> data = {1,3,2,5,3,-100,9};
    for (auto item: largestValues(buildTree(data))){
        cout << item << endl;
    }

}