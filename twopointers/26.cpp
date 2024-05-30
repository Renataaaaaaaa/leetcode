
#include <vector>
#include <iostream>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int slow = 0;
    int fast = 1;
    //不想等动slow 想等动fast
    while(fast < nums.size()){
        if (nums[fast] == nums[slow]){
            fast++;
        }else{
            nums[slow + 1] = nums[fast];
            slow++;
        }
    }
    return slow + 1;
}
int main(){
    vector<int> nums = {1,2};
    cout << removeDuplicates(nums) << endl;
    for(auto num: nums){
        cout << num << endl;
    }
}