#include <vector>
#include <iostream>
#include <ctype.h>
#include <numeric>
#include <unordered_set>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    bool after = false; 
    for (int i = 0; i < intervals.size(); i++){
        int start = max(newInterval[0], intervals[i][0]);
        int end = min(newInterval[1], intervals[i][1]);
        if (end >= start){
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
        }else{
            if (intervals[i][0] > newInterval[1] && !after){
                res.push_back(newInterval);
                after = true;
            }
            res.push_back(intervals[i]);
        }
    }
    // res.push_back(newInterval);
    // sort(res.begin(), res.end(), [](vector<int> a, vector<int>b) {return a[1] < b[1];});
    return res;
}
int main(){
    vector<vector<int>> data = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {{4,8}};
    for (auto list: insert(data, newInterval)){
        for (auto item: list){
            cout << item << " ";
        }
        cout << endl;
    }
}