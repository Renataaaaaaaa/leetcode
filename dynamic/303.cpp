#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class NumArray {
public:
    vector<int> prefixsum;
    NumArray(vector<int>& nums) {
        prefixsum = vector<int>(nums.size() + 1);
        prefixsum[0] = 0;
        int sum_cur = 0;
        for (int i = 0; i < nums.size(); i++){
            sum_cur += nums[i];
            prefixsum[i + 1] = sum_cur;
        }
    }
    
    int sumRange(int left, int right) {
        return prefixsum[right + 1] - prefixsum[left - 1 + 1];
    }
};

int main(){
    vector<int> data = {-2, 0, 3, -5, 2, -1};
    NumArray obj(data);
    cout << obj.sumRange(0,1) << endl;;

}