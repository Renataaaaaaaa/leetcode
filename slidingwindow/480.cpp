#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> big; //minHeap
priority_queue<int, vector<int>, less<int>> small;  //maxHeap
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
    if (smallSize == bigSize + 2){
        int smallTop = small.top();
        small.pop();
        smallSize--;
        bigSize++;
        big.push(smallTop);
        prune(small);
    }else if(bigSize > smallSize){
        int bigTop = big.top();
        big.pop();
        smallSize++;
        bigSize--;
        small.push(bigTop);
        prune(big);
    }
}

void addNum(int num) {
    if (small.empty() || num < small.top()){
        small.push(num);
        smallSize++;
    }else{
        big.push(num);
        bigSize++;
    }
    balance();
}
void erase(int num){
    delayed[num]++;
    if (num <= small.top()){
        smallSize--;
        if(num == small.top()){ //?
            prune(small);
        }
    }else{
        bigSize--;
        if (num == big.top()) {
            prune(big);
        }
    }
    balance();
}

//一直不会因为删除的元素而导致不平衡

double findMedian() {
    if (smallSize == bigSize + 1) { //允许小顶堆+1
        return small.top();
    }
    return ((double)small.top() + big.top()) / 2.0;
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
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    for(auto item: medianSlidingWindow(nums, 3)){
        cout << item << endl;
    }
}