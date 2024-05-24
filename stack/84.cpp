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
                int area = height * width;
                largestArea = max(area, largestArea);
            }
            poles.push(i);
        }
    }

    while(poles.size() != 0){ //right to rightmost
        int height = heights[poles.top()];
        poles.pop();
        int width = 0;
        if (poles.size() != 0){
            width = (heights.size() - 1) - (poles.top() + 1) + 1; //ATTENTION
        }else{
            width = heights.size();
        }
        int area = height * width;
        largestArea = max(area, largestArea);
    }
    return largestArea;
}

int main(){
    vector<int> data = {2,1,5,6,2,3};
    cout << largestRectangleArea(data) << endl;
}