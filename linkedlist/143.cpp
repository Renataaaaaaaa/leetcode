#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* l1){ //ATTENTION: remember to use this one
    ListNode* last = nullptr;

    while(l1!=nullptr){
        ListNode* tmp = l1->next;
        l1->next = last;
        last = l1;
        l1 = tmp;
    }
    return last;
}

void reorderList(ListNode* head) {
    ListNode* low = head;
    ListNode* fast = head;
    if (head->next == nullptr || head->next->next == nullptr) {
        return;
    }
    do{
        fast = fast->next->next;
        low = low->next;

    }while( fast != nullptr && fast->next != nullptr);
    low = reverseList(low);
    ListNode* move = head;
    while(low != nullptr){
        ListNode* move_tmp = move->next;
        ListNode* low_tmp = low->next;
        move->next = low;
        if (low == move_tmp){
            low->next = nullptr;
        }else{
            low->next = move_tmp;
        }
        move = move_tmp;
        low = low_tmp;
    }

}