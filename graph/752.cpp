#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

string help(string state, vector<int>& direction){
    string res = "";
    for (int i = 0; i < 4; i++){
        int tmp = (state[i] - '0') + direction[i];
        switch (tmp)
        {
        case 10:
            tmp = 0;
            break;
        case -1:
            tmp = 9;
            break;
        default:
            break;
        }
        res += (tmp + '0');
    }
    return res;
}
int openLock(vector<string>& deadends, string target) {
    unordered_set<string> deadends_set(deadends.begin(), deadends.end());
    if (deadends_set.find("0000") != deadends_set.end()){
        return -1;
    }
    if (target == "0000"){
        return 0;
    }
    queue<string> queue;
    // queue<string> queue2;
    queue.push("0000");

    unordered_map<string, int> dis_map;
    dis_map["0000"] = 0;
    vector<vector<int>> directions= {{1,0,0,0}, {-1,0,0,0}, {0,1,0,0}, {0,-1,0,0}, {0,0,1,0}, {0,0,-1,0}, {0,0,0,1}, {0,0,0,-1}};
    while(queue.size() != 0){
        string state = queue.front();
        int dis = dis_map[state];

        for (auto direction: directions){
            string next_state = help(state, direction);
            if (next_state == target){
                return dis + 1;
            }
            if (deadends_set.find(next_state) == deadends_set.end() && dis_map.find(next_state) == dis_map.end()){
                queue.push(next_state);
                dis_map[next_state] = dis + 1;
            }
        }
        queue.pop();
    }
    return -1;
}
