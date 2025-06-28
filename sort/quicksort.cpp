#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;
void swap(vector<int>& data, int i, int j){
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

// int partition(vector<int>& nums, int i, int j){
//     // int pivot_index = i;
//     int pivot = nums[i];
//     int p1 = i;
//     int p2 = j;
//     // swap(nums, i , pivot_index); 
//     while(p2 > p1){
//         while(p2 > p1 && nums[p2] >= pivot){
//             p2--;
//         }
//         //p2 < pivot and replace the first pivot
//         nums[p1] = nums[p2]; //
//         while(p2 > p1 && nums[p1] <= pivot){
//             p1++;
//         }
//         nums[p2] = nums[p1];
//         //p1 > pivot
//     }
//     // swap(data, pivot, p2);
//     nums[p2] = pivot;
//     return p2;
// }
// void quickSort(vector<int>& nums, int i, int j){
//     if (i >= j){
//         return;
//     }
//     int pivot = partition(nums, i, j);
//     quickSort(nums, i, pivot - 1);
//     quickSort(nums, pivot + 1, j);
// }
pair<int, int> partition(vector<int>& nums, int i, int j){
    // int pivot_index = rand() % (j - i + 1) + i;
    int pivot = nums[i];
    int p1 = i, p3 = i;
    int p2 = j, p4 = j;
    // swap(nums, i , pivot_index); 
    while(p2 > p1){
        while(p2 > p1 && nums[p2] >= pivot){
            if (nums[p2] == pivot){
                swap(nums, p2, p4);
                p4--;
            }
            p2--;
        }
        //p2 < pivot and replace the first pivot
        nums[p1] = nums[p2];
        while(p2 > p1 && nums[p1] <= pivot){
            if (nums[p1] == pivot){
                swap(nums, p1, p3);
                p3++;
            }
            p1++;
        }
        nums[p2] = nums[p1];
        //p1 > pivot
    }
    // swap(data, pivot, p2);
    nums[p2] = pivot;
    p1--;
    p2++;
    p3--;
    p4++;
    while(p3 >= i){
        swap(nums, p3, p1);
        p3--;
        p1--;
    }
    while(p4 <= j){
        swap(nums, p4, p2);
        p4++;
        p2++;
    }
    return {p1, p2};
}
void quickSort(vector<int>& nums, int i, int j){
    if (i >= j){
        return;
    }
    pair<int, int> pivot = partition(nums, i, j);
    quickSort(nums, i, pivot.first);
    quickSort(nums, pivot.second, j);
}

int main(){
    vector<int> nums = {4,4,1,4,8};
    quickSort(nums, 0, nums.size() - 1);
    for(auto item: nums){
        cout << item << endl;
    }
}