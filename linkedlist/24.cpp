#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr){ //0 or 1
        return head;
    }
    ListNode dummy(0);
    dummy.next = head;
    ListNode* move = &dummy;
    // 0  1  2  3  4

    ListNode* node1 = nullptr;
    ListNode* node2 = nullptr;
    ListNode* node3 = nullptr;
    cout << dummy.val << endl;
    while(move != nullptr && move ->next != nullptr && move ->next->next != nullptr){
        node1 = move->next;
        node2 = node1->next;
        node3 = node2->next;
        move->next = node2;
        node2->next = node1;
        node1->next = node3;
        move = node1;
    }

    return dummy.next;

}

int main(){
    vector<int> data = {1,2,3,4,5};
    printLinkedList(swapPairs(generate(data)));
}