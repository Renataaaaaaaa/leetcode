#include <vector>
#include <iostream>
#include "../array/utils.cpp"

using namespace std;

void swap(vector<int>& nums, int i, int j){
    int tmp = nums[j];
    nums[j] = nums[i];
    nums[i] = tmp;
}


void sortColors(vector<int>& nums) {
    int point1 = 0, point2 = 0, point0 = 0;
    while(point1 < nums.size() && point2 < nums.size()){
        if(nums[point2] != 2){
            if (nums[point2] == 1){
                swap(nums, point1, point2);
                point1++;
            }
            else{
                swap(nums, point1, point2);
                swap(nums, point0, point1);
                point0++;
                point1++;
            }
        }
        point2++;
        printVector(nums);
    }
}

int main(){
    vector<int> data = {2,0,1};
    sortColors(data);
    printVector(data);
}