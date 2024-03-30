#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Compare {
    bool operator()(const std::pair<char, int>& a, const std::pair<char, int>& b) const {
        return a.second < b.second; //min heap
    }
};

string frequencySort(string s) {
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); i++){
        map[s[i]]++;
    }
    std::priority_queue<pair<char, int>, std::vector<pair<char, int>>, Compare> maxHeap;
    for (const auto& pair: map){
        maxHeap.push(pair);
    }
    string res = "";
    while(maxHeap.size() != 0){
        res.append(string(maxHeap.top().second, maxHeap.top().first));
        // res.push_back(maxHeap.top().first);
        maxHeap.pop();
    }
    return res;
}

int main(){
    string s = "tree";
    cout << frequencySort(s) << endl;
}