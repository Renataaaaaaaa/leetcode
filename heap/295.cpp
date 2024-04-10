#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

//小顶堆 6 7 8 9
//大顶堆 5 4 3
//允许小顶堆为大顶堆数量+1
class MedianFinder {
public:


    priority_queue<int, vector<int>, greater<int>> queMin; //minHeap
    priority_queue<int, vector<int>, less<int>> queMax;  //maxHeap

    MedianFinder() {
    }

    void addNum(int num) {
        if (queMax.size() > 0 && num < queMax.top()){
            queMax.push(num);
            if (queMax.size() == queMin.size() + 1){
                int queMaxNum = queMax.top();
                queMax.pop();
                queMin.push(queMaxNum);
            }
        }else{
            queMin.push(num);
            if (queMin.size() == queMax.size() + 2){
                int queMinNum = queMin.top();
                queMin.pop();
                queMax.push(queMinNum);
            }
        }
    }
    
    double findMedian() {
        if (queMin.size() > queMax.size()) { //允许小顶堆+1
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }
};
int main(){
    MedianFinder work;
    work.addNum(1);
    work.addNum(2);
    cout << work.findMedian() << endl;
    work.addNum(3);
    cout << work.findMedian() << endl;
}