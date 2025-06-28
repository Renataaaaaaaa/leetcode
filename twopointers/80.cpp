
#include <vector>
#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int cur = 0;
    int right = 1;
    bool once = true;
    while(right < nums.size()){
        if (nums[right] == nums[cur]){
            if (once){
                nums[cur + 1] = nums[right];
                cur++;
                once = false;
            }
        }else{
            nums[cur + 1] = nums[right];
            once = true;
            cur++;
        }
        right++;
    }
    return cur + 1;
}

int main(){
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    cout << removeDuplicates(nums) << endl;
    for(auto item: nums){
        cout << item << endl;
    }
}