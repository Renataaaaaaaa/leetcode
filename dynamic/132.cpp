#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

//f[i, j] = min(f(i, k)) + 1
// 0 ~ 0; 0 ~ 1; 0 ~2 ..., 0 ~ n-1
int minCut(string s) {
    vector<int> cut_num(s.size(), 0);
    vector<vector<int>> isPalin(s.size(), vector<int>(s.size(), 0));
    isPalin[0][0] = 1;
    for (int i = 1; i <s.size(); i++){
        for(int j = 0; j <= i; j++){
            if (s[j] == s[i] && ( i - j < 2 || isPalin[j+1][i-1])){
                isPalin[j][i] = 1;
            }
        }
    }
    
    for(int j = 1; j < s.size(); j++){
        int cut_num_tmp = INT32_MAX;
        for(int k = 0; k <= j ; k++){
            if (isPalin[k][j]){
                if (k == 0){
                    cut_num_tmp = min(cut_num_tmp, 0);
                }else{
                    cut_num_tmp = min(cut_num_tmp, cut_num[k-1] + 1);
                }
                
            }
        }
        cut_num[j] = cut_num_tmp;
    }
    return cut_num[s.size() - 1];
}

int main(){
    string s = "aab";
    cout << minCut(s) << endl;
}