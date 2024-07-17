#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    int rightmost = 0;
    int end = 0;
    int step = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (i <= rightmost) {
            rightmost = max(rightmost, i + nums[i]);
            if (i == end){
                end = rightmost;
                step++;
            }

        }
    }
    return step;
}

// int jump(vector<int>& nums) {
//     vector<int> dp(nums.size(), nums.size() + 1);
//     dp[0] = 0;
//     for(int i = 1; i < nums.size(); i++){
//         for(int j = i - 1; j >= 0; j--){
//             if ( (i - j) <= nums[j]){
//                 dp[i] = min(dp[i] , dp[j] + 1);
//             }
            
//         }
//     }
//     return dp[nums.size() - 1];
// }

int main(){
    vector<int> nums = {2,3,1,1,4};
    cout << jump(nums) << endl;
}