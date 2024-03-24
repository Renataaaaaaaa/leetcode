#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool inRange(string s, int i){
    int res = stoi(s.substr(i, 2));
    cout << res << endl;
    return res >= 1 && res <= 26;
}
int numDecodings(string s) {
    vector<int> dp(s.size() + 1, 0);
    dp[dp.size() - 1] = 1;
    if (s[s.size() - 1] != '0'){
        dp[s.size() - 1] = 1;
    }
    for (int i = s.size() - 2; i >= 0; i--){
        if (s[i] != '0' && i + 1 < s.size() && inRange(s, i)){ //combine with following one
            dp[i] += dp[i + 2];
        }
        if (s[i] != '0'){ //don't combine with following one
            dp[i] += dp[i + 1];
        }
        cout << "i " << i  << " " << dp[i] << endl;
    }
    return dp[0];
}

int main(){
    // string s = "226";
    string s = "23123";
    cout << numDecodings(s) << endl;
}