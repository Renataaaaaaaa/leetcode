#include <vector>
#include <iostream>
using namespace std;
double getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
    unsigned long i_1 = 0;
    unsigned long i_2 = 0;
    while(true){
        cout << "K " << k << endl;

        if (i_1 == nums1.size()) { //一个数组为空
            cout << "111111" << endl;
            return nums2[i_2 + k - 1];
        }
        if (i_2 == nums2.size()) {
            cout << "1555555" << endl;
            return nums1[i_1 + k - 1];
        }
        if (k == 1){
            return min(nums1[i_1], nums2[i_2]);
        }
        int i_1_n = min(i_1 + k / 2 - 1, nums1.size() - 1);
        int i_2_n = min(i_2 + k / 2 - 1, nums2.size() - 1);
        cout << i_1_n << "      " << i_2_n << endl;
        if (nums1[i_1_n] <= nums2[i_2_n]){
            k -= i_1_n - i_1 + 1;
            i_1 = i_1_n + 1;
            
        }else{
            k -= i_2_n - i_2 + 1;
            i_2 = i_2_n + 1;
        }
        // k = (nums1.size() - 1 - i_1 + 1 + nums2.size() - 1 - i_2 + 1) / 2;
    }
    // return nums1[k];
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size_sum = nums1.size() + nums2.size();
    if (size_sum % 2 != 0){
        return getKthElement(nums1, nums2, size_sum / 2 + 1);
    }else{
        cout << "33" << endl;
        cout << getKthElement(nums1, nums2, size_sum / 2) << endl;
        cout << getKthElement(nums1, nums2, size_sum / 2 + 1) << endl;
        return (getKthElement(nums1, nums2, size_sum / 2) + getKthElement(nums1, nums2, size_sum / 2 + 1)) / 2;
    }
}
int main(){
    vector<int> nums1 = {2};
    vector<int> nums2 = {};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
}