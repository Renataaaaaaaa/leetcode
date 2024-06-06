#include <vector>
#include <iostream>
#include <ctype.h>
#include <set>
#include <queue>
#include <random>
using namespace std;
#include "utils.cpp"

class Solution {
public:
    ListNode* t_head = nullptr;
    default_random_engine e;
    // Solution(vector<int>& nums): e(static_cast<unsigned>(std::time(nullptr))) {
    //     data = nums;
    // }
    Solution(ListNode* head) {
        t_head = head;
        e.seed(static_cast<unsigned>(std::time(nullptr)));
    }
    
    int getRandom() {
        int res = 0;
        int i = 0;
        ListNode* ptr = t_head;
        while(ptr != nullptr){
            i++;
            // cout << "i - 1 " << (i - 1) << endl;
            uniform_int_distribution<unsigned> u(0, i-1);
            int rand = u(e);
            // cout << "rand" << rand << endl;
            if (rand == 0){
                res = ptr->val;
            }
            ptr = ptr->next;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    ListNode* node = generate(nums);
    Solution* solu = new Solution(node);
    cout << solu->getRandom() << endl;
    cout << solu->getRandom() << endl;
    cout << solu->getRandom() << endl;
    cout << solu->getRandom() << endl;
    cout << solu->getRandom() << endl;
    cout << solu->getRandom() << endl;
    cout << solu->getRandom() << endl;
    cout << solu->getRandom() << endl;
    
}