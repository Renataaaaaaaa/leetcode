
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
    if (p[j] == '?'){
        return true;
    }
    return s[i] == p[j];
}

bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
    dp[0][0] = true;
    for(int i = 0; i < s.size() + 1; i++){
        for(int j = 1; j < p.size() + 1; j++){
            if (p[j - 1] == '*'){
                dp[i][j] = (i >= 1 ? dp[i-1][j] : false) | dp[i][j-1];
            }else{
                if (charIsMatch(s, p, i-1, j-1)){
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
    string s = "aaa";
    string p = "bb*";
    cout << isMatch(s, p) << endl;
}