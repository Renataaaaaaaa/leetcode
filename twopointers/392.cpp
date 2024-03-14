#include <vector>
#include <iostream>
#include "../array/utils.cpp"

using namespace std;


bool isSubsequence(string s, string t) {
    if (t.size() < s.size()){
        return false;
    }
    int i = 0, j = 0;
    while(i < s.size()){
        while(j <= (t.size() - 1 ) && t[j] != s[i]){
            j++;
        } //out of bound or i == j
        if (j == t.size()){
            return false;
        }else{
            i++;
            j++;
        }
    }
    return true;
    // if (i == s.size()){
    //     return true;
    // }else{
    //     return false;
    // }
}

int main(){
    string s = "aaaaaa";
    string t = "bbaaaa";
    cout << isSubsequence(s, t) << endl;
}