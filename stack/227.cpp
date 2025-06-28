#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;


void pushStk(stack<int>& stk, char sign, int num_cur){
    if (sign == '+'){
        stk.push(num_cur);
    }else if (sign == '-'){
        stk.push(num_cur * -1);
    }else if (sign == '*'){
        int last = stk.top();
        stk.pop();
        stk.push(last * num_cur);
    }else{
        int last = stk.top();
        stk.pop();
        stk.push(last / num_cur);
    }
}
int calculate(string s) {
    stack<int> stk;
    char sign = '+'; //last 1 2 3 4
    int num_cur = 0;
    for(int i = 0; i < s.size(); i++){
        if (s[i] == ' '){
            continue;
        }else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            pushStk(stk, sign, num_cur);
            sign = s[i];
            num_cur = 0;
        }else {
            num_cur = num_cur * 10 + (s[i] - '0');
        }
    }
    pushStk(stk, sign, num_cur);    
    int res = 0;
    while( !stk.empty()){
        res += stk.top();
        stk.pop();
    }
    return res;
}
int main(){
    string s = "4/3 + 2";
    cout << calculate(s) << endl;
}