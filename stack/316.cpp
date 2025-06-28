#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

//判断当前栈顶的元素和c的比较
//如果c更小，则把c作为开始的字符字典序更小，但是要判断该字符在后边会不会再出现
string removeDuplicateLetters(string s) {
    stack<char> stk;
    int counts [256] = {0};
    bool inStk [256] = {false};
    for(auto c: s){
        counts[c]++;
    }
    for(auto c: s){
        counts[c]--;
        if (inStk[c]){
            continue;
        }
        while(!stk.empty() && c < stk.top()){
            if (counts[stk.top()] == 0){
                break;
            }
            inStk[stk.top()] = false;
            stk.pop();
        }
        stk.push(c);
        inStk[c] = true;
    }
    string res = "";
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    // string s = "bcabc";
    string s = "cdac";
    cout << removeDuplicateLetters(s) << endl;
}