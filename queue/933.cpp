#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class RecentCounter {
public:
    queue<int> times;
    RecentCounter() {
    }
    
    int ping(int t) {
        while (times.size() > 0 && t - times.front() > 3000){
            times.pop();
        }
        times.push(t);
        return times.size();
    }
};