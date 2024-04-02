#include <vector>
#include <iostream>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    for (auto &num: nums){
        if (num <= 0){
            num = nums.size() + 1;
        }
    }
    for (auto num: nums){
        if (abs(num) <= nums.size()){
            nums[abs(num) - 1] = nums[abs(num) - 1] < 0 ? nums[abs(num) - 1] : 0 - nums[abs(num) - 1];
        }
    }
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] > 0){
            return i + 1;
        }
    }
    return nums.size() + 1;
}

int main(){
    vector<int> data = {1,1};
    // vector<int> data = {3,4,-1,1};
    // vector<int> data = {7,8,9,11,12};
    cout << firstMissingPositive(data) << endl;
}