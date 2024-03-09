#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::unordered_map<std::string, int> myMap;
    vector< vector<string> > res = {  };
    for (auto st: strs){
        string old = st;
        sort (st.begin(), st.end());
        if (myMap.find(st) != myMap.end()){
            int index = myMap.at(st);
            res[index].push_back(old);
        }else{
            res.push_back(vector<string>{old});
            myMap[st] = res.size() - 1;
        }
    }
    return res;
}