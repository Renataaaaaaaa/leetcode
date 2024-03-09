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

bool isPalindrome(ListNode* head) {
    ListNode* low = head;
    ListNode* fast = head;
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    if (head->next->next == nullptr){
        return head->val == head->next->val;
    }
    do{
        fast = fast->next->next;
        low = low->next;
        cout << low->val << endl;

    }while( fast != nullptr && fast->next != nullptr);
    low = reverseList(low);
    ListNode* move = head;
    while(low != nullptr){
        if (move->val != low->val){
            return false;
        }
        move = move->next;
        low = low->next;
    }
    return true;
}