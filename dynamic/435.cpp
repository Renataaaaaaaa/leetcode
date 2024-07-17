#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

static bool compare(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}
int intervalSchedule(vector<vector<int>>& intervals){
    sort(intervals.begin(), intervals.end(), compare);
    int nums = 1;
    int right = intervals[0][1];
    for (int i = 0; i < intervals.size(); i++){
        if (intervals[i][0] >= right){
            nums++;
            right = intervals[i][1];
        }
    }
    return nums;
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    return intervals.size() - intervalSchedule(intervals);
}

