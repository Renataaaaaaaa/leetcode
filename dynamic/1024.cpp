#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

static bool compare(vector<int>& a, vector<int>& b){
    if (a[0] == b[0]){
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

int videoStitching(vector<vector<int>>& clips, int time) {
    sort(clips.begin(), clips.end(), compare);
    int curEnd = 0, nextEnd = 0;
    int i = 0, n = clips.size();
    int res = 0;
    while(i < n && clips[i][0] <= curEnd){
        while(i < n && clips[i][0] <= curEnd){
            nextEnd = max(nextEnd, clips[i][1]);
            i++;
        }
        res++;
        curEnd = nextEnd;
        if (curEnd >= time){
            return res;
        }
    }
    return -1;
}

int main(){
    vector<vector<int>> clips = {{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
    cout << videoStitching(clips, 10) << endl; 
}