#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include "utils.cpp"
using namespace std;


vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    queue<TreeNode* > queue_1;
    queue_1.push(root);
    TreeNode* front = nullptr;
    unordered_map<TreeNode*, TreeNode*> parent;
    parent[root] = nullptr;
    while(!queue_1.empty()){
        front = queue_1.front();
        if (front->left != nullptr){
            parent[front->left] = front;
            queue_1.push(front->left);
        }
        if (front->right != nullptr){
            parent[front->right] = front;
            queue_1.push(front->right);
        }
        queue_1.pop();
    }

    queue_1.push(target);
    int size = 0;
    unordered_map<TreeNode*, bool> visited;
    visited[target] = true;
    int height = 0;
    vector<int> res;
    while(!queue_1.empty()){
        size = queue_1.size();
        res = {};
        for (int i = 0; i < size; i++){
            front = queue_1.front();
            if (parent[front] != nullptr && !visited[parent[front]]){
                visited[parent[front]] = true;
                queue_1.push(parent[front]);
                res.push_back(parent[front]->val);
            }
            if (front->left != nullptr && !visited[front->left]){
                visited[front->left] = true;
                queue_1.push(front->left);
                res.push_back(front->left->val);
            }
            if (front->right != nullptr && !visited[front->right]){
                visited[front->right] = true;
                queue_1.push(front->right);
                res.push_back(front->right->val);
            }
            queue_1.pop();
        }
        height++;
        // for (auto item: res){
        //     cout << item << endl;
        // }
        if (height == k){
            return res;
        }
    }
    return {};
}

int main(){
    //[3,5,1,6,2,0,8,null,null,7,4]
    TreeNode* node_3 = new TreeNode(3);
    TreeNode* node_5 = new TreeNode(5);
    TreeNode* node_1 = new TreeNode(1);
    TreeNode* node_6 = new TreeNode(6);
    TreeNode* node_2 = new TreeNode(2);
    TreeNode* node_0 = new TreeNode(0);
    TreeNode* node_8 = new TreeNode(8);
    TreeNode* node_7 = new TreeNode(7);
    TreeNode* node_4 = new TreeNode(4);
    node_3->left = node_5;
    node_3->right = node_1;
    node_5->left = node_6;
    node_5->right = node_2;
    node_2->left = node_4;
    node_2->right = node_7;
    node_1->left = node_0;
    node_1->right = node_8;
    for(auto item: distanceK(node_3, node_5, 2 )){
        cout << item << endl;
    }
}