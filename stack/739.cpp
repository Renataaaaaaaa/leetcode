#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> data;
    data.push(0);
    vector<int> res(temperatures.size(), 0);
    for (int i = 1; i<temperatures.size(); i++){
        while(data.size()!=0 && temperatures[i] > temperatures[data.top()]){
            res[data.top()] = i - data.top();
            data.pop();        
        }
        data.push(i);
    }
    return res;
}