#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    vector<int> dp_p (nums.size(), 0);
    vector<int> dp_n (nums.size(), 0);
    // if (nums[0] > 0){
    //     dp_p[0] = nums[0];
    //     dp_n[0] = 1;
    // }else{
    //     dp_p[0] = 1; //ATTENTION: 
    //     dp_n[0] = nums[0];
    // }

    // int res = nums[0]; //ATTENTION: 开始值注意
    dp_p[0] = nums[0];
    dp_n[0] = nums[0];
    for (int i = 1; i < nums.size(); i++){
        dp_p[i] = max(dp_p[i - 1] * nums[i], max(nums[i], dp_n[i - 1] * nums[i]));
        dp_n[i] = min(dp_n[i - 1] * nums[i], min(nums[i], dp_p[i - 1] * nums[i]));

    }
    // return dp_p[nums.size() - 1];
    return *max_element(dp_p.begin(), dp_p.end());
}

int main(){
    // vector<int> data = {-2};
    vector<int> data = {-2};
    // vector<int> data = {2,3,-2,4}; //6
    // vector<int> data = {-2,3,-4,30};
    cout << maxProduct(data) << endl;
}