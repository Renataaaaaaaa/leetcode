#include <vector>
#include <iostream>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0){
        return false;
    }
    int lo = 0;
    int hi = matrix.size() * matrix[0].size() - 1;
    int mid, i, j;
    while(hi >= lo){
        mid = (lo + hi) / 2;
        i = mid / matrix[0].size();
        j = mid - matrix[0].size() * i;
        if (matrix[i][j] == target){
            return true;
        }else if (matrix[i][j] > target){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return false;
}
int main(){
    // vector<vector<int>> data = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
    vector<vector<int>> data = { {} };
    cout << searchMatrix(data, 3) << endl;
}