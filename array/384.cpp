#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
#include <random>
using namespace std;

class Solution {
public:
    vector<int> data;
    default_random_engine e;
    Solution(vector<int>& nums): e(static_cast<unsigned>(std::time(nullptr))) {
        data = nums;
    }
    
    vector<int> reset() {
        return data;
    }
    
    vector<int> shuffle() {
        vector<int> res = data;
        
        
        for(int i = 0; i < data.size(); i++){
            uniform_int_distribution<unsigned> u(i, data.size() - 1);
            int rand = u(e);
            // cout << rand << endl;
            // int rand = i + rand(i, data.size());
            int tmp = res[i];
            res[i] = res[rand];
            res[rand] = tmp;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {-6,10,184};
    Solution* obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    for(auto item: param_1){
        cout << item << " ";
    }
    cout << endl;
    vector<int> param_2 = obj->shuffle();
    for(auto item: param_2){
        cout << item << " ";
    }
    cout << endl;
    vector<int> param_3 = obj->reset();
    for(auto item: param_3){
        cout << item << " ";
    }
    cout << endl;
    vector<int> param_4 = obj->shuffle();
    for(auto item: param_4){
        cout << item << " ";
    }
    cout << endl;
    vector<int> param_5 = obj->reset();
    for(auto item: param_5){
        cout << item << " ";
    }
    cout << endl;
    vector<int> param_6 = obj->shuffle();
    for(auto item: param_6){
        cout << item << " ";
    }
    cout << endl;
}