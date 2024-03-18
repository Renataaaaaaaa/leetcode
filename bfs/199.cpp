#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include "utils.cpp"
using namespace std;

class Solution {
public:
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (root == nullptr){
        return res;
    }
    queue<TreeNode* > queue1;
    queue<TreeNode* > queue2;

    queue1.push(root);
    while(queue1.size() != 0){
        if (queue1.front()->left != nullptr){
            queue2.push(queue1.front()->left);
        }
        if (queue1.front()->right != nullptr){
            queue2.push(queue1.front()->right);
        }
        if (queue1.size() == 1){
            res.push_back(queue1.front()->val);
        }
        queue1.pop();
        if (queue1.size() == 0){
            if (queue2.size() == 0){
                break;
            }else{
                queue1 = queue2;
                queue2 = queue<TreeNode* >();
            }

        }
    }
    return res;
}
};