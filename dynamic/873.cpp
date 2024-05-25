#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;


//A[i] = A[j] + A[k] 如果存在 j <= i, k <= j
//f[i, j] = f[j, k] + 1
vector<vector<int>> find_sum(vector<int>& arr, int p, int q, int target){
    vector< vector<int> > res;
    while(q > p){
        if (target == arr[p] + arr[q]){
            res.push_back({p, q});
            p++;
            q--;
        }else if (target < (arr[p] + arr[q])){
            q--;
        }else{
            p++;
        }
    }
    return res;
}

int lenLongestFibSubseq(vector<int>& arr) {
    // int res = 0;
    vector < vector<int >> dp(arr.size(), vector<int>(arr.size(), 0)); //data structure
    for(int i = 2; i < arr.size(); i++){
        vector<vector<int>> res  = find_sum(arr, 0, i - 1, arr[i]);
        if (res.size() != 0){
            for (auto choice: res){
                int n1 = choice[0];
                int n2 = choice[1];
                if (dp[n1][n2] != 0){
                    dp[n2][i] = dp[n1][n2] + 1;
                    dp[n1][n2] = 0; //ATTENTION
                }else{
                    dp[n2][i] = 1;
                }
            }
        }
        
    }
    int res = 0;
    for (int i = 0; i < dp.size(); i++){
        for (int j = 0; j < dp.size(); j++){
            res = max(dp[i][j], res);
        }
    }
    if (res >= 1){
        return res + 2;
    }else{
        return 0;
    }
    
}

int main(){
    vector<int> data = {1,2,3,4,5,6,7,8};
    cout << lenLongestFibSubseq(data) << endl;
}