#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

//最后一个字符相同 f[i, j] = f[i - 1, j - 1] + 1
//不同 f[i, j] = max(f[i - 1, j], f[i, j -1])
int longestCommonSubsequence(string text1, string text2) {

    vector<vector<int> > dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for(int i = 1; i < text1.size() + 1; i++){
        for (int j = 1; j < text2.size() + 1; j++){
            if (text1[i-1] == text2[j-1]){ //错位
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[text1.size()][text2.size()];
}
