#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    if (heights.size() == 0){
        return 0;
    }
    if (heights.size() == 1){
        return heights[0];
    }

    stack<int> poles;
    poles.push(0);
    int largestArea = 0;
    for (int i = 1; i<heights.size(); i++){
        if (poles.size() == 0 || heights[i] > heights[poles.top()]){
            poles.push(i);
        }else{
            while(poles.size()> 0 && heights[i] < heights[poles.top()]){
                int height = heights[poles.top()];
                poles.pop(); //ATTENTION
                int width = (i - 1) - (poles.size() != 0 ? (poles.top() + 1) : 0) + 1; //
                largestArea = max(height * width, largestArea);
            }
            poles.push(i);
        }
    }

    while(poles.size() != 0){ //right to rightmost
        int height = heights[poles.top()];
        poles.pop();
        int width = (heights.size() - 1) - (poles.size() != 0 ? (poles.top() + 1) : 0) + 1;
        largestArea = max(height * width, largestArea);
    }
    return largestArea;
}

int main(){
    vector<int> data = {2,1,5,6,2,3};
    cout << largestRectangleArea(data) << endl;
}