#include <vector>
#include <iostream>
#include <ctype.h>
#include <numeric>
#include <unordered_set>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int>b) {return a[1] < b[1];});
    int nums = 1;
    int right = intervals[0][1];
    for (int i = 0; i < intervals.size(); i++){
        if (intervals[i][0] >= right){
            nums++;
            right = intervals[i][1];
        }
    }
    return intervals.size() - nums;
}

int main(){
    vector<vector<int>> data = {{1,2},{2,3},{3,4},{1,3}};
    cout << eraseOverlapIntervals(data) << endl;
}