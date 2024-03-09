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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* last = nullptr, *next = nullptr;
    while (head != nullptr){
        next = head->next;
        head->next = last;
        last = head;
        head = next;
    }
    return last; //ATTENTION
    }
};