#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

//注意 dummy节点，第一个元素的和，是第一个元素减0
int findMaxLength(vector<int>& nums) {
    for (auto& item: nums){
        if (item == 0){
            item = -1;
        }
    }
    vector<int> sums(nums.size() + 1, 0);
    unordered_map<int, int> map;
    map[0] = 0;
    int res = 0;

    for (int i = 0; i < nums.size(); i++){
        sums[i + 1] = nums[i] + sums[i];
        if (map.find(sums[i + 1] - 0) != map.end()) {
            res = max(res, (i - (map[sums[i + 1]]) + 1) );
        }else{
            map[sums[i + 1]] = i + 1;
        }
    }
    return res;   
}
int main(){
    vector<int> data = {0,1,0};
    cout << findMaxLength(data) << endl;
}
