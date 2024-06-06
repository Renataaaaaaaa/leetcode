#include "utils.cpp"
#include <unordered_set>

unordered_map<string, int> serialized_tree;
vector<TreeNode*> res;
string help(TreeNode* root){
    if (root == nullptr){
        return "#";
    }
    string s = to_string(root->val) + " ";
    s += help(root->left) + " ";
    s += help(root->right) + " ";
    if (serialized_tree.find(s) != serialized_tree.end()){
        if (serialized_tree[s] == 1){
            res.push_back(root);
            serialized_tree[s] = 2;
        }
    }else{
        serialized_tree[s] = 1;
    }
    return s;

}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    help(root);
    return res;
}

int main(){
    vector<int> nums = {1,2,3,4,-100,2,4,-100,-100,4};
    TreeNode* tree = buildTree(nums);
    vector<TreeNode* > res = findDuplicateSubtrees(tree);
    for(auto item: res){
        cout << item->val << endl;
    }
}