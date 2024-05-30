#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    for(int i = 0; i < matrix.size(); i++){
        for(int j = i; j < matrix[0].size(); j++){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;

        }
    }
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size() / 2; j++){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrix[0].size() - 1 - j];
            matrix[i][matrix[0].size() - 1 - j] = tmp;
        }
    }
}
int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    for(auto line: matrix){
        for(auto item: line){
            cout << item << " ";
        }
        cout << endl;
    }
}