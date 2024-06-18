#include <vector>
#include <iostream>
using namespace std;

//如果数字在target中，左边界
//数字不在target中，第一个插入地点不影响顺序的，返回值比target大，左边的值比target小
//数字比所有值都小 为0
//数字比所有值都大 越界
int bisect_left(vector<int> data, int target){
    int lo = 0;
    int hi = data.size() - 1;
    int mid;
    while(hi >= lo){
        mid = (lo + hi) / 2;
        if (data[mid] == target){
            hi = mid - 1;
        }else if (data[mid] < target){
            lo = mid + 1;
        }else if (data[mid] > target){
            hi = mid - 1;
        }
    }
    return lo;
}

//如果数字在target中，左边界
//数字不在target中，第一个插入地点不影响顺序的，返回值比target小，右边的值比target大
//数字比所有值都小 为0
//数字比所有值都大 越界

int bisect_right(vector<int> data, int target){
    int lo = 0;
    int hi = data.size() - 1;
    int mid;
    while(hi >= lo){
        mid = (lo + hi) / 2;
        if (data[mid] == target){
            lo = mid + 1;
        }else if (data[mid] > target){
            hi = mid - 1;
        }else if (data[mid] < target){
            lo = mid + 1;
        }
    }
    return hi;
}
//存在的时候是左边界和右边界，不存在的时候lo比target大，hi比target小

int main(){
    vector<int> data = {1,5,5,5,6,8};
    cout << bisect_right(data, 7) << endl;
    // cout << bisect_left(data, 3) << endl;
    // cout << bisect_left(data, 2) << endl;
    // cout << bisect_left(data, 0) << endl;
    // cout << bisect_left(data, 10) << endl;
    // cout << "###" << endl;
    // cout << bisect_right(data, 7) << endl;
    // cout << bisect_right(data, 3) << endl;
    // cout << bisect_right(data, 2) << endl;
    // cout << bisect_right(data, 0) << endl;
    // cout << bisect_right(data, 10) << endl;
}