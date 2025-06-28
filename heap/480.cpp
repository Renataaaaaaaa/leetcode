#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

priority_queue<int, vector<int>, greater<int>> queMin; //minHeap
priority_queue<int, vector<int>, less<int>> queMax;  //maxHeap
unordered_map<int, int> delayed;
int smallSize = 0;
int bigSize = 0;

template<typename T>
void prune(T& heap){ //ATTENTION
    while(!heap.empty()){
        int num = heap.top();
        if (delayed.find(num) != delayed.end()){
            delayed[num]--;
            if (delayed[num] == 0){
                delayed.erase(num);
            }
            heap.pop();
        }else{
            break;
        }
    }
}
void balance(){
    //进入的时候，认为两边的top是valid的
    if (smallSize == bigSize + 1){
        int smallTop = queMax.top();
        queMax.pop();
        smallSize--;
        bigSize++;
        queMin.push(smallTop);
        prune(queMax); //有新的浮上来
    }else if(bigSize == smallSize + 2){
        int bigTop = queMin.top();
        queMin.pop();
        smallSize++;
        bigSize--;
        queMax.push(bigTop);
        prune(queMin); //有新的浮上来
    }
}

void addNum(int num) {
    if (!queMax.empty() && num < queMax.top()){
        queMax.push(num);
        smallSize++;
    }else{
        queMin.push(num);
        bigSize++;
    }
    balance();
}
void erase(int num){
    delayed[num]++;
    if (num <= queMax.top()){
        smallSize--;
        if(num == queMax.top()){ //?
            prune(queMax);
        }
    }else{
        bigSize--;
        if (num == queMin.top()) {
            prune(queMin);
        }
    }
    balance();
}

//一直不会因为删除的元素而导致不平衡

double findMedian() {
    if (bigSize == smallSize + 1) { //允许小顶堆+1
        return queMin.top();
    }
    return ((double)queMin.top() + queMax.top()) / 2.0;
}

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> res;
    for(int i = 0; i < k; i++){
        addNum(nums[i]);
    }
    res.push_back(findMedian());
    for(int i = k; i < nums.size(); i++){
        addNum(nums[i]);
        erase(nums[i-k]);
        res.push_back(findMedian());
    }
    return res;
}

int main(){
    vector<int> data = {1,2,3,4,2,3,1,4,2};
    for (auto item: medianSlidingWindow(data, 3)){
        cout << item << endl;
    }
}