#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> & length){

    vector<pair<int, int>> directions = {{0,1}, {0,-1}, {-1,0},{1,0}};
    int cur = matrix[i][j];
    int res_tmp = INT32_MIN;
    for(auto direction: directions){
        int i_n = i + direction.first;
        int j_n = j + direction.second;
        if (i_n >= 0 && j_n >= 0 && i_n <matrix.size() && j_n < matrix[0].size() && matrix[i_n][j_n] > matrix[i][j]){
            if (length[i_n][j_n] != -1){
                res_tmp = max(res_tmp, length[i_n][j_n]);
            }else{
                dfs(matrix, i_n, j_n, length);
                res_tmp = max(res_tmp, length[i_n][j_n]);
            }
        }
    }
    if (res_tmp == INT32_MIN){
        length[i][j] = 1;
    }else{
        length[i][j] = 1 + res_tmp;
    }
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int res_max = INT32_MIN;
    vector<vector<int >> lengths(matrix.size(), vector<int>(matrix[0].size(), -1));
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++){
            if (lengths[i][j] == -1){
                dfs(matrix, i, j, lengths);
                res_max = max(res_max, lengths[i][j]);
            }
        }
    }
    return res_max;
}

int main(){
    vector<vector<int>> data = {{9,9,4},{6,6,8},{2,1,1}};
    cout << longestIncreasingPath(data) << endl;
}