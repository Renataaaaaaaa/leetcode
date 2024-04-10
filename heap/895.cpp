#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <stack>
using namespace std;    
    
class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> stacks;
    int maxFreq = 0;
    
    public:
        FreqStack() {
            
        }
        
        void push(int val) {
            freq[val] = freq[val] + 1;
            maxFreq = max(maxFreq, freq[val]);
            stacks[freq[val]].push(val);
        }
        
        int pop() {
            int res = stacks[maxFreq].top();
            stacks[maxFreq].pop();
            freq[res] = freq[res] - 1;
            if (stacks[maxFreq].empty()){
                maxFreq--;
            }
            return res;
        }
};

int main(){
    FreqStack freqstack;
    freqstack.push(5);
    freqstack.push(7);
    freqstack.push(5);
    freqstack.push(7);
    freqstack.push(4);
    freqstack.push(5);
    cout << freqstack.pop() << endl;
    cout << freqstack.pop() << endl;
    cout << freqstack.pop() << endl;
    cout << freqstack.pop() << endl;
}