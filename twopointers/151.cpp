#include <vector>
#include <iostream>
#include "../array/utils.cpp"

using namespace std;

string reverseWords(string s) {
    int i = s.size() - 1, j = s.size() - 1;
    string res = "";
    while(i >= 0 && s[i] == ' '){
        i--;
    }
    j = i;
    while(i >= 0){
        while(i >= 0 && s[i] != ' '){
            i--;
        }
        // cout << i << " " << j << endl;
        res += s.substr(i + 1, j - (i + 1) + 1) + " ";
        while(i >= 0 && s[i] == ' '){
            i--;
        }
        j = i;
        // cout << res << endl;
    }
    return res;
}
int main(){
    string s = "  hello   world   ";
    cout << reverseWords(s) << endl;
}