#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
unordered_map<long, long> map;
int sum = 0;
int target = 0;
// int count = 0;
void pathSumHelp(TreeNode* root, long last, int& count){
    if (root == nullptr){
        return;
    }
    cout << root->val << endl;
    if (map.find(root->val + last - target) != map.end()){
        cout << "add" << endl;
        cout <<  root->val + last - target << endl;
        for (const auto& pair : map){
            cout << pair.first << " " << pair.second << endl;
        }
        count = count + map[(root->val + last - target)];
    }
    if (map.find(root->val + last) != map.end()){
        map[root->val + last] += 1;
    }else{
        map[root->val + last] = 1;
    }

    pathSumHelp(root->left, root->val + last, count);
    pathSumHelp(root->right, root->val + last, count);

    if (map[root->val + last] > 1){
        map[root->val + last] -= 1;
    }else{
        map.erase(root->val + last);
    }
}
int pathSum(TreeNode* root, int targetSum) {
    // map[root] = root->val;
    int count = 0;
    target = targetSum;
    map[0] = 1;
    pathSumHelp(root, 0, count);
    return count;
}
};