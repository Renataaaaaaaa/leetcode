#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
//f(i,j) s的0..i能形成t的0..j的数目
//s[i] == t[j] f(i, j) = f(i - 1, j) + f(i - 1, j-1) //ATTENTION
//s[i] != t[j] f(i, j) = f(i - 1, j)
int numDistinct(string s, string t) {
    if (t.size() > s.size()){
        return 0;
    }
    vector<vector<unsigned int>> dp(s.size() + 1, vector<unsigned int>(t.size() + 1, 0));
    for (size_t i = 0; i < s.size() + 1; i++){
        for (size_t j = 0; j <= min(i, t.size()); j++){
            if (j == 0){
                dp[i][j] = 1;
            }else if (i == 0){
                dp[i][j] = 0;
            }else if (s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[s.size()][t.size()];
}
