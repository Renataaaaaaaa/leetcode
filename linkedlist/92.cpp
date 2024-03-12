#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    for (int i = 0; i < left - 1; i++){
        prev = prev->next;
    }
    cout << prev->val << endl;
    ListNode* cur = prev->next;
    ListNode* next = nullptr;
    for (int j = 0; j < (right - left); j++){
        next = cur->next;
        cur->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    return dummy.next;

}

int main(){
    vector<int> data = {1,2,3,4,5};
    ListNode* node = generate(data);
    printLinkedList(reverseBetween(node, 2,4));
}