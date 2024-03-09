#include <vector>
#include <iostream>
using namespace std;

int bisect_left(vector<int> data, int target){
    int lo = 0;
    int hi = data.size() - 1;
    int mid;
    while(hi >= lo){
        mid = (lo + hi) / 2;
        if (data[mid] >= target){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return lo;
}
int bisect_right(vector<int> data, int target){
    int lo = 0;
    int hi = data.size() - 1;
    int mid;
    while(hi >= lo){
        mid = (lo + hi) / 2;
        if (data[mid] > target){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return lo;
}

int main(){
    vector<int> data = {1,2,2,2,2,2,3,4,8};
    cout << bisect_left(data, 7) << endl;
    cout << bisect_right(data, 7) << endl;
    cout << bisect_left(data, 3) << endl;
    cout << bisect_right(data, 3) << endl;
    cout << bisect_left(data, 2) << endl;
    cout << bisect_right(data, 2) << endl;
}