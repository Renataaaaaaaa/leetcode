#include <vector>
#include <iostream>
using namespace std;

string addBinary(string a, string b) {
    string res = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int addOn = 0;
    while( i >= 0 || j >= 0){
        int c_num;
        if (i < 0) {
            c_num = (b[j] - '0') + addOn;
        }else if( j < 0){
            c_num = (a[i] - '0') + addOn;
        }else{
            c_num = (a[i] - '0') + (b[j] - '0') + addOn;
        }
        addOn = c_num >= 2;
        char c = c_num >= 2 ? c_num - 2 + '0' : c_num + '0';
        res = res + c;
        i--;
        j--;
    }
    if (addOn == 1){
        res = res + '1';
    }
    reverse(res.begin(), res.end());
    return res;
    }