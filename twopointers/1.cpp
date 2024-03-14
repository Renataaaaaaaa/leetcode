#include <vector>
#include <iostream>
#include "utils.cpp"
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++){
        map[nums[i]] = i;
    }
    int left;
    for (int i = 0; i < nums.size(); i++){
        left = target - nums[i];
        cout << left << endl;
        if (map.find(left) != map.end() && i != map[left]){
            return {i, map[left]};
        }
    }
    return {};
}

int main(){
    vector<int> data1 = {3,3};
    // vector<int> data2 = {};
    printVector(twoSum(data1, 6));
}