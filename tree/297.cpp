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

int i = 0;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stack<TreeNode* >nodes;
        TreeNode* cur = root;
        string res = "";
        while(cur != nullptr || nodes.size() != 0){
            while(cur != nullptr){
                res += to_string(cur->val);
                res += " ";
                nodes.push(cur);
                cur = cur->left;
            }
            res += "null";
            res += " ";
            cur = nodes.top()->right;
            nodes.pop();
        }
        res += "null";
        res += " ";
        return res;

    }
    // Decodes your encoded data to tree.
    // 1 3 null null

    TreeNode* deserializeHelp(vector<string>& nodes){ // 1 2 4 null null 5 null null 3 null null
        // i = i + 1;
        // what use for root ??
        cout << "i " << i << endl;
        cout << nodes[i] << endl;
        if (nodes[i] == "null"){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(nodes[i]));
        // TreeNode* node = new TreeNode(stoi(nodes[i]));
        i++;
        root->left = deserializeHelp(nodes);
        i++;
        root->right = deserializeHelp(nodes);
        return root;
    }
    TreeNode* deserialize(string data) {
        TreeNode* cur;
        stringstream st(data);
        vector<string> nodes;
        string node_val;
        while (st >> node_val){
            nodes.push_back(node_val);
        }
        i = 0;
        TreeNode* root = deserializeHelp(nodes);
        return root;
    }
};