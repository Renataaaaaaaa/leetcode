#include <vector>
#include <iostream>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0){
        return false;
    }
    int i = matrix.size() - 1;
    int j = 0;
    while( i >= 0 && j <= (matrix[0].size() - 1)){
        cout << i << " " << j << endl;
        if (matrix[i][j] == target){
            return true;
        }else if (matrix[i][j] > target){
            i--;
        }else {
            j++;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> data = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
    // vector<vector<int>> data = {  };
    cout << searchMatrix(data, 20) << endl;
}