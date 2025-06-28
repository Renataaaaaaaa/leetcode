#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

pair<int, int> calculateHelp(string s, int index){
    stack<int> stk;
    int sign = 1; //last
    int num_cur = 0;
    int i = index;
    for(i = index; i < s.size(); i++){
        if (s[i] == '('){
            // num_cur, the index of )
            pair<int, int> sub_res = calculateHelp(s, i + 1);
            num_cur = sub_res.first;
            i = sub_res.second; //')'
        }else if (s[i] == ')'){
            break;
        }else if (s[i] == ' '){
            continue;
        }else if (s[i] == '+' || s[i] == '-'){
            stk.push(sign * num_cur);
            sign = s[i] == '+' ? 1 : -1;
            num_cur = 0;
        }else{
            num_cur = num_cur * 10 + (s[i] - '0');
        }
    }
    stk.push(sign * num_cur);
    int res = 0;
    while( !stk.empty()){
        res += stk.top();
        stk.pop();
    }
    return {res, i};
}

int calculate(string s) {
    return calculateHelp(s, 0).first;
}

int main(){
    string s = "(1+(4+5+2)-3)+(6+8)";
    cout << calculate(s) << endl;
}