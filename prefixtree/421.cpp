#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;


class TreeNodee{
    public:
        TreeNodee* children[2];
        int val = 0;
    TreeNodee(){
        for (auto& child : children) {
            child = nullptr;
        }
    }
};

class prefixTree{
    public:
        TreeNodee* root;
        prefixTree(){
            root = new TreeNodee();
        }
        void insert(int num){
            // int bits[32];
            TreeNodee* root_cur = root;
            for (int i = 0; i < 32; i++){
                int bit = num >> (31 - i) & 1; // 0 or 1
                if (root_cur->children[bit] == nullptr){
                    root_cur->children[bit] = new TreeNodee();
                }
                root_cur = root_cur->children[bit];
            }
            root_cur->val = num;
        }
        int findMaxXor(int num){
            TreeNodee* root_cur = root;
            for (int i = 0; i < 32; i++){
                int bit = num >> (31 - i) & 1; // 0 or 1
                if (root_cur->children[!bit] != nullptr){ //ATTENTION
                    root_cur = root_cur->children[!bit];
                }else{
                    root_cur = root_cur->children[bit];
                }
            }
            return root_cur->val;
        }
};
class Solution {
public:
int findMaximumXOR(vector<int>& nums) {
    prefixTree* tree = new prefixTree();
    for (auto num: nums){
        tree->insert(num);
    }
    int res = 0;
    for (auto num: nums){
        res = max(res, num ^ tree->findMaxXor(num));
    }
    return res;
}
};