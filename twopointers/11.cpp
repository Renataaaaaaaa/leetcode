#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int maxArea(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int area = -1;
    while(j > i){
        area = max(area, (j - i) * min(height[i], height[j]));
        cout << "area " << area << endl;
        if (height[i] < height[j]){
            i++;
        }else{
            j--;
        }
    }
    return area;
}

int main(){
    vector<int> height = {1,1};
    cout << maxArea(height) << endl;
}