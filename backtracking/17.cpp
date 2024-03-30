#include <vector>
#include <iostream>
#include <ctype.h>
#include <numeric>
using namespace std;

unordered_map<int, vector<char>> map;
void letterCombinationsHelp(string digits, int index, string& cur_str, vector<string>& res){
    if (index == digits.size()){
        res.push_back(cur_str);
        return;
    }
    // cout << map[digits[index]].size() << endl;
    for (int i = 0; i < map[digits[index]].size(); i++){
        cur_str.push_back(map[digits[index]][i]);
        letterCombinationsHelp(digits, index + 1, cur_str, res);
        cur_str.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    map = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    string cur_str = "";
    vector<string> res;
    letterCombinationsHelp(digits, 0, cur_str, res);
    return res;

}

int main(){
    string digits = "23";
    for (auto item: letterCombinations(digits)){
        cout << item << endl;
    }
}