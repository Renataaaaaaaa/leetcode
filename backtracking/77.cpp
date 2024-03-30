#include <vector>
#include <iostream>
#include <ctype.h>
using namespace std;

void combineHelp(int n, int i, vector<int>& cur_res, vector<vector<int>>& res, int k){
    if (i == n + 1){
        if (cur_res.size() == k){
            res.push_back(cur_res);
        }
        return;
    }
    //discard
    combineHelp(n, i + 1, cur_res, res, k);
    //keep i
    cur_res.push_back(i);
    combineHelp(n, i + 1, cur_res, res, k);
    cur_res.pop_back();
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> cur_res;
    combineHelp(n, 1, cur_res, res, k);
    return res;
}

int main(){
    for (auto list: combine(4,2)){
        for (auto item: list){
            cout << item << " ";
        }
        cout << endl;
    }
}