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
                poles.pop();
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
            width = (heights.size() - 1) - (poles.top() + 1) + 1;
        }else{
            width = heights.size();
        }
        int area = height * width;
        largestArea = max(area, largestArea);
    }
    return largestArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    vector< vector<int> > nums (matrix.size(), vector<int>(matrix[0].size(), 0));
    int res = 0;
    for (int i = 0; i < matrix.size(); i++){
        vector<int> heights(matrix[0].size(), 0);
        for (int j = 0; j < matrix[0].size(); j++){
            int item = matrix[i][j] - '0';
            if (item == 0){
                cout << "55" << endl;
                nums[i][j] = 0;
                heights[j] = 0;
            }else{
                cout << "59" << endl;
                heights[j] = item + (i >= 1 ? nums[i-1][j]: 0); // TODO
                nums[i][j] = heights[j];
            }
        }
        for (auto item: heights){
            cout << item << endl;
        }
        res = max(res, largestRectangleArea(heights));
        cout << "i " << i << "res " << res << endl;
    }
    return res;
}