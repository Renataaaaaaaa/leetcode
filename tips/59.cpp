#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    int left_bound = 0, up_bound = 0;
    int right_bound = n - 1;
    int down_bound = n - 1;
    vector<vector<int>> matrix (n, vector<int>(n, 0));
    int k = 1;
    while(k <= n * n){
        for(int j = left_bound; j <= right_bound; j++){
            matrix[up_bound][j] = k++;
        }
        up_bound++;
        for(int i = up_bound; i <= down_bound; i++){
            matrix[i][right_bound] = k++;
        }
        right_bound--;
        if (k > n * n){
            break;
        }
        for(int j = right_bound; j >= left_bound; j--){
            matrix[down_bound][j] = k++;
        }
        down_bound--;
        for(int i = down_bound; i >= up_bound; i--){
            matrix[i][left_bound] = k++;
        }
        left_bound++;
    }
    return matrix;
}
int main(){
    // vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix = generateMatrix(3);
    for(auto line: matrix){
        for(auto item: line){
            cout << item;
        }
        cout << endl;
    }
}