#include "utils.cpp"


unordered_map<long, long> map;
int sum = 0;
int target = 0;
// int count = 0;
void pathSumHelp(TreeNode* root, long last, int& count){
    if (root == nullptr){
        return;
    }
    if (map.find(root->val + last - target) != map.end()){
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

int main(){
    vector<int> data = {10,5,-3,3,2,-100,11,3,-2,-100,1};
    cout << pathSum(buildTree(data), 8) << endl;
}