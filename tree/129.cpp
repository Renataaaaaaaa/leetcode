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

int sumNumbers(TreeNode* root) {
    queue<TreeNode* > queue1;
    queue<TreeNode* > queue2;
    queue1.push(root);
    // vector<int> num;
    // num.push_back(root->val);
    unordered_map<TreeNode*, int> map;
    cout << "25" << endl;
    map[root] = root->val;
    while(true){
        // TreeNode* 
        while(queue1.size() != 0){
            TreeNode* node1 = queue1.front();
            if ((node1->left != nullptr) || (node1->right != nullptr)){
                if (node1->left != nullptr){
                    map[node1->left] = map[node1]* 10 + node1->left->val;
                    queue2.push(node1->left);
                }
                if (node1->right != nullptr){
                    map[node1->right] = map[node1]* 10 + node1->right->val;
                    queue2.push(node1->right);
                }
                map.erase(node1);

            }
            queue1.pop();
        }
        if (queue2.size() == 0){
            break;
        }
        for (const auto& pair : map){
            cout << pair.first << " " << pair.second << endl;
        }
        queue1 = queue2;
        queue2 = queue<TreeNode* >();
    }
    int sum = 0;
    for (const auto& pair : map){
        sum += pair.second;
    }
    return sum;
}