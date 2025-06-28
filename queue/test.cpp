#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;
struct Compare {
    bool operator()(const int a, const int b) const {
        return a < b; //max heap
    }
};


int main(){
    priority_queue<int, vector<int>, Compare> que;
    que.push(3);
    que.push(9);
    que.push(10);
    que.push(1);
    que.push(2);
    cout << que.top() << endl;
}