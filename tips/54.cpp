#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int left_bound = 0, up_bound = 0;
    int right_bound = matrix[0].size() - 1;
    int down_bound = matrix.size() - 1;
    vector<int> res;
    while(res.size() < (matrix[0].size() * matrix.size())){
        for(int j = left_bound; j <= right_bound; j++){
            res.push_back(matrix[up_bound][j]);
        }
        up_bound++;
        for(int i = up_bound; i <= down_bound; i++){
            res.push_back(matrix[i][right_bound]);
        }
        right_bound--;
        if (res.size() == (matrix[0].size() * matrix.size())){
            break;
        }
        for(int j = right_bound; j >= left_bound; j--){
            res.push_back(matrix[down_bound][j]);
        }
        down_bound--;
        for(int i = down_bound; i >= up_bound; i--){
            res.push_back(matrix[i][left_bound]);
        }
        left_bound++;

        // cout << res.size() << endl;
    }
    return res;
}
int main(){
    // vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix = {{1}, {2}};
    for(auto item: spiralOrder(matrix)){
        cout << item << endl;
    }
}