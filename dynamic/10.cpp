#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool charIsMatch(string& s, string& p, int i, int j){
    if (i < 0){
        return false;
    }
    if (j < 0){
        return false;
    }
    if (p[j] == '.'){
        return true;
    }
    return s[i] == p[j];
}

bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
    dp[0][0] = true;
    for(int i = 0; i < s.size() + 1; i++){
        for(int j = 1; j < p.size() + 1; j++){ //j为0肯定为false
            if (p[j-1] == '*'){ //from 0
                // if (s[i] == p[j-1]){
                if (charIsMatch(s, p, i - 1, j - 2)){
                    dp[i][j] = dp[i-1][j] | (j >= 2 ? dp[i][j-2]: false); //匹配一次，保留*，和不用*
                }else{
                    dp[i][j] = (j >= 2 ? dp[i][j-2]: false); //
                }
            }else{
                if (charIsMatch(s, p, i - 1, j - 1)){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
    }
    return dp[s.size()][p.size()];
}
int main(){
    string s = "aab";
    string p = "c*a*b";
    cout << isMatch(s, p) << endl;
}