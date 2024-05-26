#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>

using namespace std;
//一定会按照dis逐渐递增的顺序压入queue中

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue<pair<int, int>> past;
    vector<vector<int>> dismat(mat.size(), vector<int>(mat[0].size(), -1));
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[0].size(); j++){
            if (mat[i][j] == 0){
                past.push(make_pair(i, j));
                dismat[i][j] = 0;
            }
        }
    }
    
    vector<pair<int, int>> directions = {{0,1}, {0,-1}, {-1,0},{1,0}};
    while(past.size() != 0){
        int i = past.front().first;
        int j = past.front().second;
        int dis = dismat[i][j];
        for (auto direction: directions){
            int i_n = i + direction.first;
            int j_n = j + direction.second;
            if (i_n >= 0 && i_n <mat.size() && j_n >= 0 && j_n < mat[0].size() && dismat[i_n][j_n] == -1){
                past.push(make_pair(i_n, j_n));
                dismat[i_n][j_n] = dis + 1; //minimum?
            }
        }
        past.pop();
    }
    return dismat;
}
