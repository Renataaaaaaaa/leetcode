#include <vector>
#include <iostream>
#include <ctype.h>
#include <numeric>
using namespace std;
void combinationSum3Help(int k, int i, int target, vector<int>& cur_res, vector<vector<int>>& res){
    int sum = accumulate(cur_res.begin(), cur_res.end(), 0);
    cout << sum << endl;
    if (sum > target){
        return;
    }
    if (i == 10 || cur_res.size() == k){
        if (cur_res.size() == k && sum == target){
            res.push_back(cur_res);
        }
        return;
    }
    //discard
    combinationSum3Help(k, i + 1, target, cur_res, res);
    //keep
    cur_res.push_back(i);
    combinationSum3Help(k, i + 1, target, cur_res, res);
    cur_res.pop_back();
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> cur_res;
    combinationSum3Help(k, 1, n, cur_res, res);
    return res;
}

int main(){
    int k = 9;
    int n = 45;
    for (auto list: combinationSum3(k, n)){
        for (auto item: list){
            cout << item << " ";
        }
        cout << endl;
    }
}