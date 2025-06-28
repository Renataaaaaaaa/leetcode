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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;
        bool p_changed = false, q_changed = false;
        while(p != nullptr && q != nullptr && p != q){
            if (!p_changed && p -> next == nullptr){
                p = headB;
                p_changed = true;
            }else{
                p = p->next;
            }
            if (!q_changed && q -> next == nullptr){
                q = headA;
                q_changed = true;
            }else{
                q = q->next;
            }
        }
        if (p != q){
            return nullptr;
        }else{
            return p;
        }
    }
};