#include <vector>
#include <iostream>
using namespace std;
//找到第一个大于等于它的
//左边界
int find(int target, vector<pair<int, int>>& vec){
    int lo = 0;
    int hi = vec.size() - 1;
    int mid = 0;
    while(hi >= lo){
        mid = lo + (hi - lo) / 2;
        if (vec[mid].second > target){
            hi = mid - 1;
        }else if (vec[mid].second < target){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return lo;
}
static bool compare(pair<int, int>& a, pair<int, int>& b){
    return a.second < b.second;
}
vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<int> result;
    vector<pair<int, int> > sorted_start;
    for(int i = 0; i < intervals.size(); i++){
        sorted_start.push_back({i, intervals[i][0]});
    }
    sort(sorted_start.begin(), sorted_start.end(), compare);
    for(auto item: intervals){
        int res = find(item[1], sorted_start);
        if (res == sorted_start.size()){
            result.push_back(-1);
        }else{
            result.push_back(sorted_start[res].first);
        }
    }
    return result;
}
int main(){
    vector<vector<int>> intervals = {{3,4},{2,3},{1,2}};
    for(auto item: findRightInterval(intervals)){
        cout << item << endl;
    }
}