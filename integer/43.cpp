#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;


string multiply(string num1, string num2) {
    vector<int> res(num1.size() + num2.size(), 0);
    for(int i = 0; i < num1.size(); i++){
        for(int j = 0; j < num2.size(); j++){
            int tmp = (num1[i]-'0') * (num2[j]-'0');
            res[i+j] += tmp / 10;
            res[i+j+1] += tmp % 10;
        }
    }
    string res_string = "";
    int addOn = 0;
    for(int i = res.size() - 1; i >= 0; i--){
        if (res[i] + addOn < 10){
            res_string += to_string(res[i] + addOn);
            addOn = 0;
        }else{
            res_string += to_string((res[i] + addOn) % 10);
            addOn = (res[i] + addOn)/ 10;
        }
    }
    int prefix0_index = 0;
    reverse(res_string.begin(), res_string.end());
    for(int i = 0; i < res_string.size(); i++){
        if (res_string[i] == '0'){
            prefix0_index++;
        }else{
            break;
        }
    }
    res_string = res_string.substr(prefix0_index);
    return res_string == "" ? "0" : res_string;
}

int main(){
    string num1 = "123456789";
    string num2 = "987654321";
    cout << multiply(num1, num2) << endl;
}