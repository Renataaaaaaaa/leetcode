#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> maxHeap;
    int size = 0;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (auto num: nums){
            add(num);
            cout << maxHeap.size() << endl;
        }
    }
    
    int add(int val) {
        if (maxHeap.size() < size){
            maxHeap.push(val);
        }else{
            if (val > maxHeap.top()){
                maxHeap.pop();
                maxHeap.push(val);
                // return maxHeap.top();
            }else{
                // return maxHeap.top();
            }
        }
        return maxHeap.top();
    }
};