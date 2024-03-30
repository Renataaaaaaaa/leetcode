#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

struct Compare {
    bool operator()(const std::vector<int>& a, const std::vector<int>& b) const {
        return (pow(a[0],2) + pow(a[1], 2)) > (pow(b[0],2) + pow(b[1], 2)); //min heap
    }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    std::priority_queue<vector<int>, std::vector<vector<int>>, Compare> minHeap;
    // priority_queue<vector<int>, vector<> queue;
    for (auto point: points){
        minHeap.push(point);
    }
    vector<vector<int>> res;
    for(int i = 0; i < k; i++){
        res.push_back(minHeap.top());
        minHeap.pop();
    }
    return res;
}
int main(){
    vector<vector<int>> data = {{3,3}, {5,-1}, {-2,4}};
    for (auto list: kClosest(data, 2)){
        for (auto item: list){
            cout << item << " ";
        }
        cout << endl;
    }
}