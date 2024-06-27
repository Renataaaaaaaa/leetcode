#include <vector>
#include <iostream>
using namespace std;


int minimumDeleteSum(string s1, string s2) {
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    for(int j = 1; j < s2.size() + 1; j++){
        dp[0][j] = static_cast<int>(s2[j-1]) + dp[0][j-1];
    }
    for(int i = 1; i < s1.size() + 1; i++){
        dp[i][0] =  static_cast<int>(s1[i-1]) + dp[i-1][0];
    }
    for(int i = 1; i < s1.size() + 1; i++){
        for(int j = 1; j < s2.size() + 1; j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(dp[i][j-1] + static_cast<int>(s2[j-1]), dp[i-1][j]  + static_cast<int>(s1[i-1]));
            }
        }
    }
    return dp[s1.size()][s2.size()];
}

int main(){
    string word1 = "sea";
    string word2 = "eat";
    cout << minimumDeleteSum(word1, word2) << endl;
}