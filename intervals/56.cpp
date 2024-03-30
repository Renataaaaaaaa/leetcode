#include <vector>
#include <iostream>
#include <ctype.h>
#include <numeric>
#include <unordered_set>
using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //sort
    if (intervals.size() == 1){
        return intervals;
    }
    sort(intervals.begin(), intervals.end(), [](vector<int> vec1, vector<int> vec2){return vec1[0] < vec2[0];});
    // for (auto interval: intervals){
    //     cout << "14" << endl;
    //     for (auto item: interval){
    //         cout << item << endl;
    //     }
    // }
    vector< vector<int> > res;
    vector<int> cur = intervals[0];
    for(vector< vector<int> >::size_type i = 1; i < intervals.size(); i++){
        if (cur[1] >= intervals[i][0]){
            cur[1] = max(cur[1], intervals[i][1]);
        }else{
            res.push_back(cur);
            cur = intervals[i];
        }
    }
    res.push_back(cur);
    return res;
}
