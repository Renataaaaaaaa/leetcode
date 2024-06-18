#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

//[v1, v2] => true
bool compare(const vector<int>& v1, const vector<int>& v2){
    if (v1[0] < v2[0]){
        return true;
    }else if (v1[0] > v2[0]){
        return false;
    }else if (v1[0] == v2[0]){
        return v1[1] > v2[1];
    }
}
int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int res = 0;
    sort(intervals.begin(), intervals.end(), compare); 
    int i = 0;
    int j = 1;
    while(j < intervals.size()){
        if(intervals[j][0] >= intervals[i][1]){ //not overlap
            i = j;
            j = i + 1;
        }else if (intervals[j][1] <= intervals[i][1]){ // cover
            // i--;
            j++;
            res += 1;
        }else{   //overlap
            i = j;
            j = i + 1;
        }
    }
    return intervals.size() - res;
}

int main(){
    vector<vector<int>> data = {{1,2},{1,2}};
    cout << removeCoveredIntervals(data) << endl;
}