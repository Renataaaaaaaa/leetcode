#include <cctype>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool isPalindrome(string s) {
    int p = 0;
    int q = s.size() - 1;
    while(q >= p && q >= 0 && p < s.size()){
        if(!isalnum(s[p])){
            p++;
        }else if(!isalnum(s[q])){
            q--;
        }else if (tolower(s[p]) != tolower(s[q])){
            return false;
        }else{
            p++;
            q--;
        }

    }
    return true;
}