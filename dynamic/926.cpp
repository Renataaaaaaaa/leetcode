#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

//前i-1以0结尾f 还是1结尾 g
//s[i] == 1: f[i] = f[i-1] + 1; g[i] = min(f[i-1], g[i-1])
//s[i] == 0: f[i] = f[i-1]; g[i] = min(f[i-1], g[i-1]) + 1
int minFlipsMonoIncr(string s) {
    vector<int> f(s.size(), 0);
    vector<int> g(s.size(), 0);

    if (s[0] == '1'){
        f[0] = 1;
        g[0] = 0;
    }else{
        f[0] = 0;
        g[0] = 1;
    }
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i] == '1'){
            f[i] = f[i - 1] + 1; //flip my self to 0
            g[i] = min(f[i - 1], g[i - 1]); //stay
        }else{
            f[i] = f[i-1];
            g[i] = min(f[i - 1], g[i - 1]) + 1;
        }
    }
    return min(f[s.size() - 1], g[s.size() - 1]);
}

int main(){
    string s = "00011000";
    cout << minFlipsMonoIncr(s) << endl;
}
