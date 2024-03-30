#include <vector>
#include <iostream>
#include <ctype.h>
using namespace std;

void letterCasePermutationHelp(string s, int index, vector<string>& res, string & path){
    if (index == s.size()){
        res.push_back(path);
        return;
    }
    if (s[index] >= 'a' && s[index] <= 'z'){
        path += static_cast<char>(toupper(s[index]));
        letterCasePermutationHelp(s, index + 1, res, path);
    }else if (s[index] >= 'A' && s[index] <= 'Z'){
        path += static_cast<char>(toupper(s[index]));
        letterCasePermutationHelp(s, index + 1, res, path);
    }
    path.pop_back();
    path += s[index];
    letterCasePermutationHelp(s, index + 1, res, path );
    path.pop_back();
}
vector<string> letterCasePermutation(string s) {
    vector<string> res;
    string path = "";
    letterCasePermutationHelp(s, 0, res, path);
    return res;
}
    
int main(){
    string s = "C";
    for (auto res: letterCasePermutation(s)){
        cout << res << endl;
    }
}