#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
bool attempt = false;
bool isPalindrome(string s, int p, int q) {

    while(q >= p && q >= 0 && p < s.size()){
        if(!isalnum(s[p])){
            p++;
        }else if(!isalnum(s[q])){
            q--;
        }else if (tolower(s[p]) != tolower(s[q]) && !attempt){
            attempt = true;
            return isPalindrome(s, p + 1, q) || isPalindrome(s, p, q - 1);
        }else if (tolower(s[p]) != tolower(s[q]) && attempt){
            return false;
        }else{
            p++;
            q--;
        }
    }
    return true;
}

bool validPalindrome(string s) {
    return isPalindrome(s, 0, s.size() - 1);
}
};