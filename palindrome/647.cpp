
#include <vector>
#include <iostream>
using namespace std;

int countSubstringsHelp(string s, int left, int right){
    // int left = center_i, right = center_i;
    int res = 0;
    while(left >= 0 && right < s.size()){
        if (s[left] != s[right]){
            return res;
        }
        left--;
        right++;
        res++;
    }
    return res;
}
int countSubstrings(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++){
        res += countSubstringsHelp(s, i, i);
        res += countSubstringsHelp(s, i, i+1);
    }
    return res;
}