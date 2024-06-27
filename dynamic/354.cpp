#include <vector>
#include <iostream>
using namespace std;

static bool compare(const vector<int>& v1, const vector<int>& v2){
    if(v1[0] < v2[0]){
        return true;
    }else if (v1[0] > v2[0]){
        return false;
    }else{
        if (v1[1] > v2[1]){
            return true;
        }else if (v1[1] <= v2[1]){
            return false;
        }
    }
}
int lengthOfLIS(vector<int> nums) {
    vector<int> top(nums.size(),0);
    // 牌堆数初始化为 0
    int piles = 0;
    for (int i = 0; i < nums.size(); i++) {
        // 要处理的扑克牌
        int poker = nums[i];

        /***** 搜索左侧边界的二分查找 *****/
        int left = 0, right = piles;
        while (left < right) {
            int mid = (left + right) / 2;
            if (top[mid] > poker) {
                right = mid;
            } else if (top[mid] < poker) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        /*********************************/

        // 没找到合适的牌堆，新建一堆
        if (left == piles) piles++;
        // 把这张牌放到牌堆顶
        top[left] = poker;
    }
    // 牌堆数就是 LIS 长度
    return piles;
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), compare);

    vector<int> envelopes_h;
    for(auto e: envelopes){
        envelopes_h.push_back(e[1]);
    }
    return lengthOfLIS(envelopes_h);
    // vector<int> dp(envelopes_h.size(), 1);
    // dp[0] = 1;
    // for(int i = 0; i < dp.size(); i++){
    //     for (int j = 0; j < i; j++){
    //         if (envelopes_h[i] > envelopes_h[j]){
    //             dp[i] = max(dp[j] + 1, dp[i]);
    //         }
            
    //     }
    // }
    // return *max_element(dp.begin(), dp.end());
}
int main(){
    vector<vector<int>> nums = {{5,4},{6,4},{6,7},{2,3}};
    cout << maxEnvelopes(nums) << endl;
}