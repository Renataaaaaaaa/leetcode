#include "utils.cpp"
#include <queue>

int widthOfBinaryTree(TreeNode* root) {
    vector<pair<TreeNode*, unsigned long long> > queue_1;
    queue_1.push_back(make_pair(root, 0));

    unsigned long long res_max = 1, res = 0;
    int size = 0;
    pair<TreeNode*, unsigned long long> front;
    while(!queue_1.empty()){
        size = queue_1.size();
        for (int i = 0; i < size; i++){
            front = queue_1.front();
            if (front.first->left != nullptr){
                queue_1.push_back(make_pair(front.first->left, 2 * front.second));
            }
            if (front.first->right != nullptr){
                queue_1.push_back(make_pair(front.first->right, 2 * front.second + 1));
            }
            queue_1.erase(queue_1.begin());
        }
        cout << queue_1[0].second << " " << queue_1[queue_1.size() - 1].second << endl;
        if(!queue_1.empty()){
            res_max = max (queue_1[queue_1.size() - 1].second - queue_1[0].second + 1, res_max);
        }
    }
    return res_max;
}
int main(){
    vector<int> data = {1,1,1,1,1,1,1,-100,-100,-100,1,-100,-100,-100,-100,2,2,2,2,2,2,2,-100,2,-100,-100,2,-100,2 };
    TreeNode* node = buildTree(data);
    cout << widthOfBinaryTree(node) << endl;
}