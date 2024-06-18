#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

vector<int> diffWaysToCompute(string expression) {
    vector<int> res = {};
    for(int i = 0; i < expression.size(); i++){
        if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
            vector<int> left = diffWaysToCompute(expression.substr(0, i-1-0+1));
            vector<int> right = diffWaysToCompute(expression.substr(i+1, expression.size()-1-(i+1)+1));
            for(auto l: left){
                for(auto r: right){
                    if (expression[i] == '*'){
                        res.push_back(l * r);
                    }else if (expression[i] == '+'){
                        res.push_back(l + r);
                    }else if (expression[i] == '-'){
                        res.push_back(l - r);
                    }
                    
                }
            }
        }
    }
    if (res.empty()){
        res = {stoi(expression)};
    }
    return res;
}

int main(){
    string s = "2*3-4*5";
    for(auto item: diffWaysToCompute(s)){
        cout << item << endl;
    }
}