#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


int minAddToMakeValid(string s) {
    stack<char> stk;
    int need_right = 0;
    int res = 0; //res为人为添加的括号以维持平衡
    for(auto c: s){
        if (c == '('){
            need_right++; //为什么不进行needleft--? 因为后出现的(, 不能满足之前的对于左括号的需求
        }else{
            need_right--;
            if (need_right == -1){
                need_right = 0;
                res++;
            }
        }
    }
    return res + need_right;
}

int main(){
    string s = "(((";
    cout << minAddToMakeValid(s) << endl;
}