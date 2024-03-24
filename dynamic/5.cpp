#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

string longestPalindrome(string s) {
    if (s.size() == 0){
        return "";
    }
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 1));
    for (int i = 0; i < dp.size(); i++){
        dp[i][i] = 1;
    }
    // string res = "";
    int max_len_i = 0;
    int max_len = INT16_MIN;
    for (int l = 2; l <= s.size(); l++){
        for (int i = 0; i < (s.size() - l + 1); i++){
            int j = i + l - 1;
            cout << " l " << l << " i " << i  << " j " << j << endl;
            if (s[i] != s[j]){
                dp[i][j] = false;
            }else{
                dp[i][j] = dp[i+1][j-1];
                if (dp[i][j] && j - i + 1 > max_len){
                    max_len = j - i + 1;
                    max_len_i = i;
                }
            }
        }
    }
    if (max_len == INT16_MIN){
        return s.substr(0, 1);
    }else{
        return s.substr(max_len_i, max_len);
    }
}
int main(){
    string s = "babad";
    // string s = "cbbd";
    // string s = "bb";
    cout << longestPalindrome(s) << endl;
}