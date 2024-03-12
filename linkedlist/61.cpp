#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

ListNode* rotateRight(ListNode* head, int k) {

    if (head == nullptr || k <= 1 || head->next == nullptr){
        return head;
    }
    ListNode* head_old = head;
    int num = 1;
    while(head->next != nullptr){
        head=head->next;
        num++;
    }
    ListNode* end = head;
    cout << "end" << end->val << endl;

    head = head_old;
    if (k % num == 0){
        return head_old;
    }
    k = (num - (k % num)) - 1;
    cout << k << endl;
    for (int i = 0; i < k ; i++){
        head = head->next;
    }
    ListNode* breakpoint = head;
    cout << "breakpoint" << breakpoint->val << endl;

    ListNode* next = breakpoint->next;
    breakpoint->next = nullptr;
    end->next = head_old;
    return next;
}

int main(){
    vector<int> data = {1,2,3};
    printLinkedList(rotateRight(generate(data), 3));
}