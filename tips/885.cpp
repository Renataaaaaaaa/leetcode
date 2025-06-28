#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;
vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> res;
    int left_bound = cStart, right_bound = cStart + 1;
    int upper_bound = rStart, down_bound = rStart + 1;
    while(res.size() < rows * cols){
        for(int j = left_bound; j <= right_bound; j++){
            if (upper_bound >= 0 && upper_bound < rows && j >= 0 && j < cols){
                res.push_back({upper_bound , j});
            }
            
        }
        // upper_bound; //TODO
        left_bound--;
        for(int i = upper_bound + 1; i <= down_bound; i++){
            if (i >= 0 && i < rows && right_bound >= 0 && right_bound < cols){
                res.push_back({i, right_bound});
            }
            
        }
        upper_bound--;
        // right_bound++;
        for(int j = right_bound - 1; j >= left_bound; j--){
            if (down_bound >= 0 && down_bound < rows && j >= 0 && j < cols){
                res.push_back({down_bound, j});
            }
            
        }
        right_bound++;
        // down_bound++;
        for(int i = down_bound - 1; i > upper_bound; i--){ //TODO
            if (i >= 0 && i < rows && left_bound >= 0 && left_bound < cols){
                res.push_back({i, left_bound});
            }
            
        }
        down_bound++;
        // left_bound--;
    }
    return res;
}
int main(){
    for ( auto item: spiralMatrixIII(1, 4, 0, 0)){
        cout << item[0] << " " << item[1] << endl;
    }
}