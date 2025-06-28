
#include <vector>
#include <iostream>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int unique = 0;
    int right = 1;
    //不想等动slow 想等动fast
    while(right < nums.size()){
        if (nums[right] == nums[unique]){
            right++;
        }else{
            nums[unique + 1] = nums[right];
            unique++;
        }
    }
    return unique + 1;
}
int main(){
    vector<int> nums = {1,2};
    cout << removeDuplicates(nums) << endl;
    for(auto num: nums){
        cout << num << endl;
    }
}