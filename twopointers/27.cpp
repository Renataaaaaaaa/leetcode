
#include <vector>
#include <iostream>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    int fast = 0;
    //fast遇到val 跳过，否则直接赋值给slow
    while(fast < nums.size()){
        if (nums[fast] == val){
            fast++;
        }else{
            nums[slow] = nums[fast];
            slow++;
            fast++;
        }
    }
    return slow;
}
int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    cout << removeElement(nums, 2) << endl;
    for(auto num: nums){
        cout << num << endl;
    }
}