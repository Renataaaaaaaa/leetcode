#include <vector>
#include <iostream>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int lo = 1;
    int hi = arr.size() - 2;
    int mid = 0;
    while (hi >= lo){
        mid = (lo + hi) / 2;
        if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid + 1]){
            return mid;
        }else if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid + 1]){ //ascending
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return mid;
}