#include <vector>
#include <iostream>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        // 0, 0, i, j
        sum.resize(matrix.size());
        for (auto& row : sum) {
            row.resize(matrix[0].size());
        }

        for (int i = 0; i < matrix.size(); i++){
            int sum_j = 0;
            for (int j = 0; j < matrix[0].size(); j++){
                sum_j = sum_j + matrix[i][j];
                sum[i][j] = (i == 0 ? 0 : sum[i-1][j]) + sum_j;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2][col2] - (row1 == 0 ? 0 : sum[row1-1][col2]) - (col1 == 0 ? 0 :sum[row2][col1-1]) + 
            ( (row1 !=0 && col1 !=0) ? sum[row1-1][col1-1] : 0);
    }
    vector< vector<int>> sum;
};