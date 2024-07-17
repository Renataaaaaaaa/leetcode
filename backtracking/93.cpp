#include <vector>
#include <iostream>
#include <ctype.h>
#include <numeric>
using namespace std;


bool isValid(string s, int i, int j){
    // if (j - i >= 3 || i > j){
    //     return false;
    // }
    if (s[i] == '0' && i != j){
        return false;
    }
    int num = stoi(s.substr(i, j - i + 1));
    if (num >= 0 && num <= 255){ //00
        return true;
    }
    return false;
}
string generateIp(vector<string> s){
    string res = "";
    for (int i = 0; i < s.size() - 1; i++){
        res += s[i];
        res += ".";
    }
    res += s.back();
    return res;
}
void restoreIpAddresses(string s, int i_index, int left, vector<string>& cur_res, vector<string>& res){
    if (left == -1){
        if (i_index == s.size()){
            string validIp = generateIp(cur_res);
            res.push_back(validIp);
        }
        return;
    }
    for(int j = i_index; j < s.size() && j < i_index + 3; j++){
        if (isValid(s, i_index, j)){
            cur_res.push_back(s.substr(i_index, j - i_index + 1));
            restoreIpAddresses(s, j + 1, left - 1, cur_res, res);
            cur_res.pop_back();
        }
    }
}
vector<string> restoreIpAddresses(string s) {
    vector<string> cur_res;
    vector<string> res;
    restoreIpAddresses(s, 0, 3, cur_res, res);
    return res;

}

int main(){
    for(auto item: restoreIpAddresses("25525511135")){
        cout << item << endl;
    }
}