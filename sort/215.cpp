#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:
void swap(vector<int>& data, int i, int j){
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}
int partition(vector<int>& data, int i, int j){
    if (i == j){
        return i;
    }
    // int pivot = data[i]; 
    int pivot_index = rand() % (j - i + 1) + i;
    int pivot = data[pivot_index];
    int p1 = i;
    int p2 = j;
    swap(data, i , pivot_index); 
    while(p2 > p1){
        while(p2 > p1 && data[p2] >= pivot){
            p2--;
        }
        //p2 < pivot and replace the first pivot
        data[p1] = data[p2];
        while(p2 > p1 && data[p1] <= pivot){
            p1++;
        }
        data[p2] = data[p1];
        //p1 > pivot
    }
    // swap(data, pivot, p2);
    data[p2] = pivot;
    return p2;
}
int findKthLargest(vector<int>& nums, int k) {
    int pivot_index = partition(nums, 0, nums.size() - 1);
    int i = 0;
    int j = nums.size() - 1;
    while((nums.size() - pivot_index) != k){
        if ((nums.size() - pivot_index) > k){
            i = pivot_index + 1;
            pivot_index = partition(nums, pivot_index + 1, j);
        }else{
            j = pivot_index - 1;
            pivot_index = partition(nums, i, pivot_index - 1);
        }
    }
    return nums[pivot_index];
}
};