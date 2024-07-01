#include <vector>
#include <iostream>
using namespace std;

int rob(vector<int>& nums) { //往回看
    vector<int> dp(nums.size() + 2, 0);
    for(int i = 2; i < nums.size() + 2; i++){
        dp[i] = max(nums[i - 2] + dp[i-2], dp[i-1]);
    }
    return dp[dp.size() - 1];
}
int main(){
    vector<int> data = {2,7,9,3,1};
    cout << rob(data) << endl;
}