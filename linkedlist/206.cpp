#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;


ListNode* reverseList(ListNode* head) {
    // if (head == nullptr || head->next == nullptr){
    //     return head;
    // }
    ListNode* prev = nullptr;
    ListNode* next_tmp = nullptr;
    while (head != nullptr){
        next_tmp = head->next;
        head->next = prev;
        prev = head;
        head = next_tmp;
    }
    return prev; //ATTENTION
}

int main(){
    vector<int> data = {};
    ListNode* node = generate(data);
    printLinkedList(reverseList(node));
}