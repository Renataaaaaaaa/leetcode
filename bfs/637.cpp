#include <vector>
#include <iostream>
#include <queue>
#include "utils.cpp"
using namespace std;

vector<double> averageOfLevels(TreeNode* root) {
    vector<double > res;
    queue<TreeNode* > queue_1;
    queue<TreeNode* > queue_2;
    queue_1.push(root);
    double sum = 0.0;
    int num = 0;
    while(!queue_1.empty()){ //ATTENTION：也可以进来的时候记录size
        sum = 0.0;
        num = 0;
        while(!queue_1.empty()){
            TreeNode* node = queue_1.front();
            if (node->left != nullptr){
                queue_2.push(node->left);
            }
            if (node->right != nullptr){
                queue_2.push(node->right);
            }

            queue_1.pop();
            sum += node->val;
            num++;
        }
        res.push_back(sum / num);
        if (queue_2.empty()){
            break;
        }
        queue_1 = queue_2;
        queue_2 = queue<TreeNode* >();
    }
    return res;
}

int main(){
    vector<int> data = {3,9,20,15,7};
    for (auto item: averageOfLevels(buildTree(data))){
        cout << item << endl;
    }
}