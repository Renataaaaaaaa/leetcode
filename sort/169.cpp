#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;
int majorityElement(vector<int>& nums) {
    
    sort(nums.begin(), nums.end());
    int mid = nums.size() / 2;
    return nums[mid];
}

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl;
}