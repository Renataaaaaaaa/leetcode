#include <vector>
#include <iostream>
#include <queue>
using namespace std;


vector<int> nums;
int count(int i, int j){
    if (i >= j){
        return 1;
    }
    if (nums[j - i] != 0){
        return nums[j - i];
    }
    int res = 0;
    for(int k = i; k <= j; k++){
        int left_num = count(i, k - 1);
        int right_num =  count(k + 1, j);
        res += left_num * right_num;
    }
    nums[j - i] = res;
    return res;
}

int numTrees(int n) {
    for(int i = 0; i < n; i++){
        nums.push_back(0);
    }
    int res = count(1, n);
    return res;
}

int main(){
    cout << numTrees(3) << endl;
}