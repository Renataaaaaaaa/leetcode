#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>

using namespace std;

bool oneDiff(string a, string b){
    bool diff = false;
    for (int i = 0; i < a.size(); i++){
        if (a[i] != b[i]){
            if (diff){
                return false;
            }else{
                diff = true;
            }
        }
    }
    return true;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    vector<vector<int>> adjacent_list(wordList.size(), vector<int>());
    for (int i = 0; i < wordList.size(); i++){
        for (int j = i + 1; j < wordList.size(); j++){
            if (oneDiff(wordList[i], wordList[j])){
                adjacent_list[i].push_back(j);
                adjacent_list[j].push_back(i);
            }
        }
    }
    queue<int> past;
    past.push(wordList.size() - 1);

    vector<int> dis_list (wordList.size(), -1);
    dis_list[wordList.size() - 1] = 0;
    while(past.size() != 0){
        int cur = past.front();
        int dis = dis_list[cur];
        for (auto neighbor: adjacent_list[cur]){
            if (dis_list[neighbor] == -1){
                past.push(neighbor);
                dis_list[neighbor] = dis + 1;
            }
            if (wordList[neighbor] == endWord){
                return dis_list[neighbor] + 1;
            }
        }
        past.pop();
    }
    return 0;

}
