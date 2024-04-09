#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
#include "utils.cpp"
using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serializeHelp(TreeNode* root){
        if (root == nullptr){
            return "#";
        }
        string s = to_string(root->val) + " ";
        s += serializeHelp(root->left) + " ";
        s += serializeHelp(root->right) + " ";
        return s;
    }
    string serialize(TreeNode* root) {
        string s = serializeHelp(root);
        return s;
    }

    TreeNode* deserializeHelp(vector<string>& nodes, int& i){ // 1 2 4 null null 5 null null 3 null null

        if (nodes[i] == "#"){
            return nullptr;
        }
        cout << nodes[i] << endl;
        TreeNode* root = new TreeNode(stoi(nodes[i]));
        // TreeNode* node = new TreeNode(stoi(nodes[i]));
        i++;
        root->left = deserializeHelp(nodes, i);
        i++;
        root->right = deserializeHelp(nodes, i);
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
        int i = 0;
        TreeNode* root = deserializeHelp(nodes, i);
        return root;
    }
};

int main(){
    vector<int> data = {1,2,3,-100,-100,4,5};
    TreeNode* root = buildTree(data);
    Codec codec;
    // cout << codec.serialize(root) << endl;
    cout << codec.deserialize(codec.serialize(root)) -> val << endl;
}