#include <vector>
#include <iostream>
#include <queue>
#include "utils.cpp"
using namespace std;


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
    if (root == nullptr){
        return res;
    }
    queue<TreeNode* > queue_1;
    queue_1.push(root);
    TreeNode* front = nullptr;
    int height = 0;
    int level_size = 0;
    // vector<bool> visited (graph.size(), false);
    // visited[index] = true;
    res.push_back({root->val});
    int level_num = 0;
    while(!queue_1.empty()){
        level_num++;
        level_size = queue_1.size();
        vector<int> res_level;
        for (int i = 0; i < level_size; i++){
            front = queue_1.front();
            if (front->left != nullptr){
                queue_1.push(front->left);
                res_level.push_back(front->left->val);
            }
            if (front->right != nullptr){
                queue_1.push(front->right);
                res_level.push_back(front->right->val);
            }
            queue_1.pop();
        }
        if (res_level.size() != 0){
            if (level_num % 2 != 0){
                reverse(res_level.begin(), res_level.end());
            }
            res.push_back(res_level);
        }
        
        // height++;
    }
    // cout << index << " " << height << endl;
    return res;
}

int main(){
    vector<int> data = {3,9,20, -100 ,-100,15,7};
    TreeNode* node =  buildTree(data);
    for (auto line: zigzagLevelOrder(node)){
        for (auto item: line){
            cout << item << " ";
        }
        cout << endl;
    }
}