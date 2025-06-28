#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

bool compare(const pair<int, int> & a, const pair<int, int> & b){
    return a.first < b.first;
}
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int res = w;
    vector<pair<int, int>> data; //按照profits 排序 profit, capital
    for(int i = 0; i < profits.size(); i++){
        data.push_back(make_pair(capital[i], profits[i]));
    }
    sort(data.begin(), data.end(), compare);
    int j = 0;
    priority_queue<int, vector<int>, less<int>> que;
    for(int i = 0; i < k; i++){
        for(; j < data.size(); j++){
            if (data[j].first <= w){
                que.push(data[j].second);
            }else{
                break;
            }
        }
        if (que.empty()){
            break;
        }
        w += que.top();
        que.pop();
    }
    return w;
}

int main(){
    vector<int> profits = {1,2,3};
    vector<int> capital = {0,1,1};
    cout << findMaximizedCapital(2, 0, profits, capital) << endl;
}