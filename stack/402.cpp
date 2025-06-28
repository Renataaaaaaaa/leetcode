
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

string removeKdigits(string num, int k) {
    stack<int> stk;
    for(int i = 0; i < num.size(); i++){
        while(!stk.empty() && k > 0 && (num[i] - '0') < stk.top()){ //todo
            k--;
            stk.pop();
        }
        stk.push(num[i] - '0');
    }
    while(k > 0){
        stk.pop();
        k--;
    }
    string res = "";
    while(!stk.empty()){
        res += to_string(stk.top());
        stk.pop();
    }
    reverse(res.begin(), res.end());
    size_t pos = res.find_first_not_of('0');
    if (pos == std::string::npos) {
        return "0";
    }
    return res.substr(pos);
}

int main(){
    string num = "123";
    cout << removeKdigits(num, 3) << endl;
}