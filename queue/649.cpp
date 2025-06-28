#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include "utils.cpp"
using namespace std;
// bool victory(vector<bool>& banned_status, string& senate, char ch){
//     for(int i = 0; i < banned_status.size(); i++){
//         if (senate[i] != ch && !banned_status[i]){
//             return false;
//         }
//     }
//     return true;
// }

// string predictPartyVictory(string senate) {
//     vector<bool> banned_status(senate.size(), false);
//     queue<char> qu;
//     for(auto ch: senate){
//         qu.push(ch);
//     }
//     int R_baned = 0, D_baned = 0;
//     int i = 0;
//     while(true){
//         char ch = qu.front();
//         if (banned_status[i] || ( ch == 'R' && R_baned >= 1) ||  (ch == 'D' && D_baned >= 1)){
//             qu.pop();
//             qu.push(ch);
//             if (!banned_status[i]){
//                 ch == 'R' ? (R_baned--) : (D_baned--); //?
//             }
//             banned_status[i] = true;
//         }else{
//             // i没有被ban
//             if (victory(banned_status, senate, ch)){
//                 break;
//             }
//             ch == 'R' ? (D_baned++) : (R_baned++);
//             qu.pop();
//             qu.push(ch);
//         }
//         i++;
//         if (i == senate.size()){
//             i = 0;
//         }
//     }
//     return qu.front() == 'R' ? "Radiant": "Dire";
// }


string predictPartyVictory(string senate) {
    int n = senate.size();
    queue<int> radiant, dire;
    for (int i = 0; i < n; ++i) {
        if (senate[i] == 'R') {
            radiant.push(i);
        }
        else {
            dire.push(i);
        }
    }
    while (!radiant.empty() && !dire.empty()) {
        if (radiant.front() < dire.front()) {
            radiant.push(radiant.front() + n);
        }
        else {
            dire.push(dire.front() + n);
        }
        radiant.pop();
        dire.pop();
    }
    return !radiant.empty() ? "Radiant" : "Dire";
}
int main(){
    string senate = "DDRRR";
    cout << predictPartyVictory(senate) << endl;
}