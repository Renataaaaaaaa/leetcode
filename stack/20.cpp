#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

bool isPair(char a, char b){
    return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}

bool isValid(string s) {
    stack<char> stk;
    for(auto c: s){
        if (c == '(' || c == '[' || c == '{'){
            stk.push(c);
        }else{
            if (!stk.empty() && isPair(stk.top(), c)){
                stk.pop();
            }else{
                return false;
            }
        }
    }
    return stk.empty();
}
int main(){
    string s = "(]";
    cout << isValid(s) << endl;
}