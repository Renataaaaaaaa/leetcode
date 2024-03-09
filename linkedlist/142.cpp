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

ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr){
        return nullptr;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    do{
        fast = fast->next->next;
        slow = slow->next;
    }while((slow != fast && fast!= nullptr && fast->next != nullptr));
    ListNode* slow_2 = head;
    while(slow!=nullptr && slow->next !=nullptr && slow != slow_2){
        slow_2 = slow_2->next;
        slow = slow->next;
    }
    if (slow != slow_2){
        return nullptr;
    }else{
        return slow_2;
    }
}