#include <vector>
#include <iostream>
using namespace std;

int iterateMatrix (vector<vector<int>>& matrix, int target){
    int i = matrix.size() - 1;
    int j = 0;
    int num = 0;
    while(i >= 0){
        while(j <= matrix.size() - 1 && matrix[i][j] < target){
            j++;
        }
        // j is the first one bigger than target
        cout << " j " << j << endl;
        num += j;
        i = i - 1;
    }
    cout << "num" << num << endl;
    return num;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int lo = matrix[0][0];
    int hi = matrix[matrix.size() - 1][matrix.size() - 1];
    int mid = 0, less_count = 0;
    while(hi >= lo){
        cout << "lo " << lo << " hi  " << hi << endl;
        mid = (lo + hi) / 2;
        cout << "mid " << mid << endl;
        less_count = iterateMatrix(matrix, mid);

        if (less_count < k){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return hi;
}