
#include <vector>
#include <iostream>
#include "utils.cpp"
#include <unordered_map>
using namespace std;


int findMinAbs(vector<int> & nums){
    if (nums.size() == 1){
        return 0;
    }
    int i = 0;
    while(i < nums.size() && nums[i] < 0){
        i++;
    }
    cout << "i " << i << endl;
    if (i == nums.size() || (i > 0 && abs(nums[i-1]) < abs(nums[i]))){
        return (i - 1);
    }else{
        return i;
    }

}

vector<int> sortedSquares(vector<int>& nums) {
    if (nums.size() == 0 ){
        return {};
    }
    //sort n logn
    int min_abs = findMinAbs(nums);
    int left = min_abs - 1;
    int right = min_abs + 1;
    cout << "min_abs" << nums[min_abs] <<  endl;
    vector<int> res;
    res.push_back(nums[min_abs] * nums[min_abs]);
    while(left >= 0 || right <= (nums.size() - 1)){
        cout << left << " " << right << endl;
        if (right == nums.size()){
            res.push_back(nums[left] * nums[left]);
            left--;
        }else if (left < 0){
            res.push_back(nums[right] * nums[right]);
            right++;
        }else if (abs(nums[left]) < abs(nums[right])){
            res.push_back(nums[left] * nums[left]);
            left--;
        }else{
            res.push_back(nums[right] * nums[right]);
            right++;
        }
    }
    return res;
}

int main(){
    // vector<int> data = {-23,-23,-21,-19,-17,-16,-15,-14,-14,-9,-6,-6,-6,-4,-3,-3,-3,1,4,11,15,16,20,21,22};
    vector<int> data = {-5,-3,-2,-1};
    printVector(sortedSquares(data));
}