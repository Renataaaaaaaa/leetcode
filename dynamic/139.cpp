#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

    for (int l = 1; l <= s.size(); l++){
        for (int i = 0; i < (s.size() - l + 1); i++){
            int j = i + l - 1;
            cout << " l " << l << " i " << i  << " j " << j << endl;
            for (int k = i + 1; k <= j; k++){ //support aa not support a
                if (dp[i][k - 1] && dp[k][j]){
                    dp[i][j] = true;
                }
            }
            if (!dp[i][j]){
                if (find(wordDict.begin(), wordDict.end(), s.substr(i, j - i + 1)) != wordDict.end()){
                    dp[i][j] = true;
                }
            }
        }
    }
    return dp[0][s.size()-1];
}

int main(){
    // string s = "applepenapple";
    // vector<string> data = {"apple", "pen", "apple"};
    string s = "catsandog";
    vector<string> data = {"cats","dog","sand","and","cat"};
    cout << wordBreak(s, data) << endl;
}