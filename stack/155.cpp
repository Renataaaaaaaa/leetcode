#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if (minStk.empty()){
            minStk.push(val);
        }else if (val <= minStk.top()){
            minStk.push(val);
        }
    }
    
    void pop() {
        if (!minStk.empty() && stk.top() == minStk.top()){
            minStk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
int main(){
    MinStack* obj = new MinStack();
    obj->push(0);
    obj->push(1);
    obj->push(0);
    cout << obj->getMin() << endl;
    obj->pop();
    // cout << obj->top() << endl;
    cout << obj->getMin() << endl;
}
