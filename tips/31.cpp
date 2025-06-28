#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

void swap(vector<int>& nums, int i , int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
void nextPermutation(vector<int>& nums) {
    int i , j;
    for(i = nums.size() - 1; i > 0; i--){
        if (nums[i-1] < nums[i]){
            for(j = nums.size() - 1; j > 0; j--){
                if (nums[j] > nums[i-1]){
                    swap(nums, i-1, j);
                    break;
                }
            }
            break;
        }
    }
    reverse(nums.begin() + i, nums.end());
}

int main(){
    vector<int> nums = {4,5,2,6,3,1};
    nextPermutation(nums);
    for(auto item: nums){
        cout << item << endl;
    }
}