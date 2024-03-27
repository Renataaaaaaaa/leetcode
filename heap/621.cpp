#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

int getMax(unordered_map<char, int>& map, unordered_map<char, int>& cool){
    char res_char = ' ';
    int max = 0;
    for (const auto & pair: map){
        if (pair.second > max && cool[pair.first] == 0){
            max = pair.second;
            res_char = pair.first;
        }
    }
    return res_char;
}
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> map;
    unordered_map<char, int> cool;
    for (int i = 0; i < tasks.size(); i++){
        map[tasks[i]]++;
        cool[tasks[i]] = 0;
    }
    int res = 0;
    while(true){
        for (auto& pair: cool){
            pair.second =  pair.second - 1 > 0 ? pair.second - 1 : 0;
        }
        char res_char = getMax(map, cool);
        cout << res_char << endl;
        if (res_char == ' '){
            res++;
            continue;;
        }
        cool[res_char] = n + 1;
        map[res_char]--;
        res++;
        bool all_finised = true;
        for (const auto & pair: map){
            if (pair.second  != 0){
                all_finised = false;
            }
        }
        if (all_finised){
            break;
        }
    }
    return res;
}
int main(){
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << leastInterval(tasks, 3) << endl;
}