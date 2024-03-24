#include <vector>
#include <iostream>
#include <queue>
using namespace std;


int climbStairs(int n) {

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
        cout << i << " " << dp[i] << endl;
    }
    return dp[n];
}

int main(){
    cout << climbStairs(3) << endl;
}