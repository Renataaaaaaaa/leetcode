#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    for(int i = 1; i < nums1.size() + 1; i++){
        for(int j = 1; j < nums2.size() + 1; j++){
            if (nums1[i-1] == nums2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[nums1.size()][nums2.size()];
}

int main(){
    vector<int> nums1 = {1,4,2};
    vector<int> nums2 = {1,2,4};
    cout << maxUncrossedLines(nums1, nums2) << endl;
}