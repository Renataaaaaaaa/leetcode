#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int left = 0, right = 0;
    int delete_num = 0;
    int res = 0;
    int res_max = 0;
    for (int right = 0; right < nums.size(); right++){
        if (nums[right] == 1){
            res++;
        }else{
            delete_num++;
        }
        if (delete_num > 1){
            while(nums[left] == 1){
                res--;
                left++;
            }
            left++;
            delete_num--;
        }
        cout << "res " << res << endl;
        res_max = max(res_max, (delete_num == 0 ? (res - 1) : res));
    }
    return res_max;
}

int main(){
    vector<int> data = {1,1,1,0,1,0,0,0,1,1,1,1};
    cout << longestSubarray(data) << endl;
}