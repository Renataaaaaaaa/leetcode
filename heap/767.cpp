#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

struct Compare{
    bool operater(pair<char, int>& a, pair<char, int>& b){
        return a.second > b.second;
    }
};
int getMax(unordered_map<char, int>& map, char last){
    char res_char = ' ';
    int max = 0;
    for (const auto & pair: map){
        if (pair.second > max && pair.first != last){
            max = pair.second;
            res_char = pair.first;
        }
    }
    return res_char;
}
string reorganizeString(string s) {
    unordered_map<char, int> map;
    // priority_queue<pair<char, int>, vector<pair<char, int>> , Compare> maxHeap;
    for (int i = 0; i < s.size(); i++){
        map[s[i]]++;
    }
    // for (const auto& pair: map){
    //     maxHeap.push(pair);
    // }

    string res = "";
    char last = ' ';
    while(true){
        char op = getMax(map, last);
        if (op != ' '){
            res += op;
            last = op;
            map[op]--;
        }else{
            break;
        }
    }
    bool all_finised = false;
    for (const auto& pair: map){
        if (pair.second != 0){
            all_finised = false;
        }
    }
    if (!all_finised){
        return "";
    }
    return res;
}
int main(){
    string s = "aaab";
    cout << reorganizeString(s) << endl;
}