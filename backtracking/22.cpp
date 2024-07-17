#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;


void generateParenthesisHelp(int left_left, int right_left, vector<string>& res, string& cur){
    if (left_left == 0 && right_left == 0){
        res.push_back(cur);
        return;
    }

    if (left_left > 0){
        cur = cur + "(";
        generateParenthesisHelp(left_left - 1, right_left, res, cur);
        cur.pop_back();
    }
    if (left_left == right_left){
        return;
    }
    if (right_left > 0){
        cur = cur + ")";
        generateParenthesisHelp(left_left, right_left - 1, res, cur);
        cur.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    string cur = "";
    generateParenthesisHelp(n, n, res, cur);
    return res;
}

int main(){
    for (auto str: generateParenthesis(3)){
        cout << str << endl;
    }
}