#include <vector>
#include <iostream>
using namespace std;


int findUnsortedSubarray(vector<int>& nums) {
    int max = INT32_MIN;
    int min = INT32_MAX;
    int right = 0, left = 0;
    for(int i = 0; i < nums.size(); i++){
        if (nums[i] >= max){
            max = nums[i];
        }else{
            right = i;
        }
    }
    for(int i = nums.size() - 1; i >= 0; i--){
        if (nums[i] <= min){
            min = nums[i];
        }else{
            left = i;
        }
    }
    cout << left << " " << right << endl;
    return right - left + 1;
}
int main(){
    vector<int> nums = {1,2,3,3,3};
    cout << findUnsortedSubarray(nums) << endl;
}