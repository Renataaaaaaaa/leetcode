#include <vector>
#include <iostream>
using namespace std;

bool search(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    int mid;
    while(hi >= lo){

        mid = (lo + hi) / 2;
        cout << "mid " << mid << " " << nums[mid] << endl;

        while (hi > lo && nums[mid] == nums[lo] && nums[mid] == nums[hi]){
            lo++;
            hi--;
        }
        cout << lo << " " << hi << endl;
        if (nums[mid] == target){
            return true;
        }
        if (nums[mid] < nums[lo] || nums[mid] < nums[hi]){ //latter, small ones
            if ((nums[mid] > target) || (nums[mid] < target && nums[hi] < target)){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }else{
            if ((nums[mid] < target) || (nums[mid] > target && nums[lo] > target)){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
    }
    return false;
}
int main(){
    vector<int> data = {1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1};
    // vector<int> data = {3,1,1,1,1};
    // vector<int> data = {1,1,1,0,1};
    // vector<int> data = {0,1};
    cout << search(data, 13) << endl;;
}