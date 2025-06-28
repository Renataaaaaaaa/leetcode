
#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

bool checkSize(ListNode* head, int range){
    int count = 0;
    while(head != nullptr){
        head = head->next;
        count++;
    }
    return count >= range;
}

ListNode* reverseBetween(ListNode* prev, int left, int right) {

    ListNode *cur = prev->next;
    ListNode *next;
    for (int i = 0; i < right - left; i++) {
        next = cur->next; //把next头插进来
        cur->next = next->next;
        next->next = prev->next; //重点
        prev->next = next;
    }
    return cur;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* tmp = nullptr;
    int i = 0;
    while(prev != nullptr){
        if (!checkSize(prev->next, k)){
            break;
        }
        prev = reverseBetween(prev, i, i + k - 1);
        i += k;
    }
    return dummy.next;
}
int main(){
    vector<int> data = {1,2,3,4,5};
    ListNode* node = generate(data);
    printLinkedList(reverseKGroup(node, 2));
}