#include <vector>
#include <iostream>
#include <ctype.h>
#include <numeric>
using namespace std;


bool isValid(string s, int i, int j){
    if (j - i >= 3 || i > j){
        return false;
    }
    if (s[i] == '0' && i != j){
        return false;
    }
    cout << s.substr(i, j - i + 1) << endl;
    // int num = 0;
    int num = stoi(s.substr(i, j - i + 1));
    // try{
    //     int num = stoi(s.substr(i, j - i + 1));
    // }catch (exception){
    //     return false;
    // }
    
    if (num >= 0 && num <= 255){ //00
        return true;
    }
    return false;
}
void restoreIpAddresses(string s, int i_index, int left, vector<string>& cur_res, vector<string>& res){
    if (left == 0){
        if (isValid(s, i_index, s.size() - 1)){
            cur_res.push_back(s.substr(i_index, s.size() - 1 - i_index + 1));
            string res_tmp = "";
            for (auto str: cur_res){
                res_tmp += str;
                res_tmp += ".";
            }
            res.push_back(res_tmp.substr(0, res_tmp.size() - 1));
            cur_res.erase(cur_res.end() - 1);
            return;
        }else{
            return;
        }
    }
    for(int j = i_index; j < s.size(); j++){
        if (isValid(s, i_index, j)){
            cur_res.push_back(s.substr(i_index, j - i_index + 1));
            restoreIpAddresses(s, j + 1, left - 1, cur_res, res);

            cur_res.erase(cur_res.end() - 1);
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
    
}