#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> nums;
    for (auto str: tokens){
        if( !(str == "+" || str == "-" || str == "*" || str == "/")){
            nums.push(stoi(str));
        }else{
            int op1 = nums.top();
            nums.pop();
            int op2 = nums.top();
            nums.pop();
            int res = 0;
            if (str == "+"){
                res = op1 + op2;
            }else if (str == "-"){
                res = op2 - op1;
            }else if (str == "*"){
                res = op1 * op2;
            }else if (str == "/"){
                res = op2 / op1;
            }
            cout << res << endl;
            nums.push(res);
        }
    }
    return nums.top();
}