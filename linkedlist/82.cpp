#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;


ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* move = dummy;
    ListNode* next;
    while(move != nullptr && move->next != nullptr){
        next = move->next;
        bool skip = false;
        while(next->next != nullptr && next->val == next->next->val){
            skip = true;
            next = next->next;
        }
        if (skip){
            move->next = next->next;
        }else{
            move = move->next;
        }   
        
    }
    return dummy->next;
}

int main(){
    vector<int> nums = {1,1,1,2,3};
    ListNode* head = deleteDuplicates(generate(nums));

    printLinkedList(head);
}