#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
#include <random>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    vector<int> res(2);
    for(int i = 0; i < nums.size(); i++){
        int target_index = abs(nums[i]) - 1;
        if (nums[target_index] < 0){
            res[0] = abs(nums[i]);
        }else{
            nums[target_index] = -nums[target_index];
        }

    }
    for(int i = 0; i < nums.size(); i++){
        if (nums[i] > 0){
            res[1] = i + 1;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {1,2,2,4};
    for(auto item: findErrorNums(nums)){
        cout << item << endl;
    }
}