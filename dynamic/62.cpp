#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (i == 0 & j == 0){
                dp[i][j] = 1;
            }else{
                dp[i][j] = (i == 0 ? 0 : dp[i-1][j]) + (j == 0 ? 0 : dp[i][j-1]);
            }
            
        }
    }
    return dp[m-1][n-1];
}
