#include <vector>
#include <iostream>
using namespace std;


string build(string s){
    string res;
    for(auto ch: s){
        if (ch == '#'){
            res.pop_back();
        }else{
            res.push_back(ch);
        }
    }
    return res;
}

bool backspaceCompare(string s, string t) {
    return build(s) == build(t);
}

int main(){
    string a = "bxj##tw";
    string b = "bxj###tw";
    cout << backspaceCompare(a, b) << endl;
    // cout << backspaceString(b, 2) << endl;
}