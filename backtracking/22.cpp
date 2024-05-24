#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;


void generateParenthesisHelp(int left_left, int right_left, vector<string>& res, string cur){
    if (left_left == 0){
        for (int i = 0; i < right_left; i++){
            cur = cur + ")";
        }
        res.push_back(cur);
        return;
    }
    int length = cur.size();
    cur = cur + "(";
    generateParenthesisHelp(left_left - 1, right_left, res, cur);
    cur = cur.substr(0, length);

    if (left_left >= right_left){
        return;
    }
    length = cur.size();
    cur = cur + ")";
    generateParenthesisHelp(left_left, right_left - 1, res, cur);
    cur = cur.substr(0, length);

}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    generateParenthesisHelp(n, n, res, "");
    return res;
}

int main(){
    for (auto str: generateParenthesis(3)){
        cout << str << endl;
    }
}