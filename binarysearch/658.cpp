#include <vector>
#include <iostream>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int lo = 0;
    int hi = arr.size() - 1;
    int mid, index;
    while(hi >= lo){
        mid = (lo + hi) / 2;
        if (arr[mid] >= x){
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    int left = lo - 1; //ATTENTION
    int right = lo;
    for (int i = 0; i < k; i++){
        if (left < 0 ){ //ATTENTION:
            right++;
        }else if (right > (int(arr.size()) - 1)){
            left--;
        }else if (x - arr[left] <= arr[right] - x){
            left--;
        }else {
            right++;
        }
    }
    vector<int> res(arr.begin() + left + 1, arr.begin() + right);
    return res;
}

int main(){
    // vector<int> data = {1,1,1,10,10,10};
    vector<int> data = {1,1,1,9,10,10,10};
    // vector<int> data = {1};
    for(auto item: findClosestElements(data, 4, 0)){
        cout << item << endl;
    }
}