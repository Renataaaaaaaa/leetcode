
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;


int lastStoneWeightII(vector<int>& stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int n = stones.size(), m = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    dp[0][0] = true;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j - stones[i-1] >= 0){
                dp[i][j] = dp[i][j] | dp[i-1][j - stones[i-1]];
            }
        }
    }
    for (int j = m;; --j) {
        if (dp[n][j]) {
            return sum - 2 * j;
        }
    }
}

int main(){
    vector<int> stones = {2,7,4,1,8,1};
    cout << lastStoneWeightII(stones) << end;
}