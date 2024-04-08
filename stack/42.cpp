#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;


int trap(vector<int>& height){
    stack<int> mono_des_height;
    int res = 0;
    for (int i = 0; i < height.size(); i++){
        while(mono_des_height.size() > 0 && height[i] > height[mono_des_height.top()]){
            int height_m = height[mono_des_height.top()];
            mono_des_height.pop();
            if (mono_des_height.size() == 0){
                break;
            }
            int height_c = min(height[i], height[mono_des_height.top()]) - height_m;
            int width = i - mono_des_height.top() - 1;
            cout << width * height_c << endl;
            res += width * height_c;
        }
        mono_des_height.push(i);
    }
    return res;
}
int main(){
    vector<int> data = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(data) << endl;
}