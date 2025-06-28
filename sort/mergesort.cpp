#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;


void merge(vector<int>& nums, int left , int mid, int right){
    vector<int> res;
    int i = left, j = mid + 1;
    while(i <= mid || j <= right){
        if(j > right || (i <= mid && (nums[i] < nums[j]))){
            res.push_back(nums[i]);
            i++;
        }else{
            res.push_back(nums[j]);
            j++;
        }
    }
    for(auto item: res){
        nums[left] = item;
        left++;
    }
}
void mergesort(vector<int>& nums, int i, int j){
    if (i >= j){
        return;
    }
    int mid = i + (j-i) / 2;
    mergesort(nums, i, mid);
    mergesort(nums, mid + 1, j);
    merge(nums, i, mid, j);
}

int main(){
    vector<int> nums = {1,3,4,9,5,12312,434,-1};
    mergesort(nums, 0, nums.size() - 1);
    for(auto item: nums){
        cout << item << endl;
    }
}