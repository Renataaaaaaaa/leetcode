#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    int addOn = 0,  l1_val = 0, l2_val = 0;
    while(l1 != nullptr || l2 != nullptr){
        l1_val = 0,  l2_val = 0;
        if (l1 != nullptr){
            l1_val = l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr){
            l2_val = l2->val;
            l2 = l2->next;
        }
        int sum_tmp = l1_val + l2_val + addOn;
        tail->next = new ListNode(sum_tmp % 10); //ATTENTION
        addOn = sum_tmp / 10;
        tail = tail->next;
    }
    if (addOn){
        tail->next = new ListNode(1);
    }
    return dummy.next;
}

int main(){
    vector<int> data_1 = {};
    vector<int> data_2 = {};
    ListNode* node1 = generate(data_1);
    ListNode* node2 = generate(data_2);
    cout << addTwoNumbers(node1, node2) << endl;
}