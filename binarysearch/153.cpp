#include <vector>
#include <iostream>
using namespace std;

int findMin(vector<int>& nums) {
    int lo = 0;
    int hi = nums.size() - 1;
    int mid;
    while(hi >= lo){
        mid = (lo + hi) / 2;
        cout << "mid " << mid << endl;
        // if (nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]){
        //     return nums[mid];
        // }
        if (nums[mid] <= nums[nums.size() - 1]){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return nums[lo];
    
}