#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;

class SmallestInfiniteSet {
public:
    int minPositive = 1;
    priority_queue<int, vector<int>, greater<int>> minQue;
    unordered_set<int> queue_num;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int res = 0;
        if (minQue.empty()){
            res = minPositive;
            minPositive++;
        }else{
            if (minPositive < minQue.top()){
                res = minPositive;
                minPositive++; // ?
            }else if (minPositive > minQue.top()){
                res = minQue.top();
                minQue.pop();
            }else{
                res = minPositive;
                minPositive++;
                minQue.pop();
            }
        }
        return res;
    }
    
    void addBack(int num) { //得判断现在堆里没有
        if (queue_num.find(num) != queue_num.end()){
            return;
        }
        minQue.push(num);
        queue_num.insert(num);
    }
};

int main(){
    SmallestInfiniteSet* s = new SmallestInfiniteSet();
    s->addBack(2);
    s->addBack(2);
    s->addBack(2);
    cout << s->popSmallest() << endl;
    cout << s->popSmallest() << endl;
    cout << s->popSmallest() << endl;
    // s->addBack(1);
    // cout << s->popSmallest() << endl;
    // cout << s->popSmallest() << endl;
    // cout << s->popSmallest() << endl;
}