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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = dummy;
    while(fast->next != nullptr && n > 0){
        fast = fast->next;
        n--;
    }
    ListNode* slow = dummy;
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    // ListNode* tmp = slow->next;
    // if (tmp->next != nullptr){
    //     slow->next = tmp->next;
    // }else{
    //     slow->next = nullptr;
    // }
    // tmp = nullptr;
    cout << (dummy->next == nullptr) << endl;
    return dummy->next;
}