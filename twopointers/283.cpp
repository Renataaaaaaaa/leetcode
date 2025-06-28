#include <vector>
#include <iostream>
#include "../array/utils.cpp"

using namespace std;

void swap(vector<int>& nums, int i, int j){
    int tmp = nums[j];
    nums[j] = nums[i];
    nums[i] = tmp;
}

void moveZeroes(vector<int>& nums) {
    int p_0 = 0, right = 0;
    while (right < nums.size()){
        if (nums[right] != 0){
            swap(nums, p_0, right);
            p_0++;
        }
        right++;
    }
}

int main(){
    vector<int> data= {0};
    moveZeroes(data);
    printVector(data);
}