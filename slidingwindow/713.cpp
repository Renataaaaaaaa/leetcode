#include <vector>
#include <iostream>
using namespace std;

// 右边到了边界，左边一直收敛到满足条件为止
// 新增的数量事之前的子数组每个加上d，就是righ - left + 1
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int left = 0;
    int product = 1;
    int res = 0;
    for(int right = 0; right < nums.size(); right++){
        product = product * nums[right];
        while(product >= k && left <= right){
            product = product / nums[left++];
        }
        res += right - left + 1;  //ATTENTION
    
    }
    return res;
}
int main(){
    vector<int> data = {10,5,2,6};
    int k = 100;
    cout << numSubarrayProductLessThanK(data, k) << endl;
}