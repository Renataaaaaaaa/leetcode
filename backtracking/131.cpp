#include <vector>
#include <iostream>
#include <ctype.h>
#include <numeric>
using namespace std;

bool isPalin(string s, int i, int j){
    if (i == j){
        return true;
    }
    while(j > i){
        if (s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void partitionHelp(string s, int i_index, int j_index, vector<vector<string>>& res, vector<string>& cur_res){
    if (j_index == s.size()) {
        res.push_back(cur_res);
    }
    for(int j = j_index; j < s.size(); j++){
        if (isPalin(s, i_index, j)){
            cur_res.push_back(s.substr(i_index, j - i_index + 1));
            partitionHelp(s, j + 1, j + 1, res, cur_res);
            cur_res.erase(cur_res.end()-1);
        }
    }
}


vector<vector<string>> partition(string s) {
    vector<string> cur_res;
    vector<vector<string>> res;
    partitionHelp(s, 0, 0, res, cur_res);
    return res;
}
