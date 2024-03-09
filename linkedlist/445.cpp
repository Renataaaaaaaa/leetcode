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

 ListNode* reverseList(ListNode* l1){
    ListNode* last = nullptr;
    while(l1!=nullptr){
        ListNode* tmp = l1->next;
        l1->next = last;
        last = l1;
        l1 = tmp;
    }
    return last;
 }

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    int addsOn = 0;
    ListNode* last = nullptr;
    ListNode* res = nullptr;
    while(l1 != nullptr || l2 != nullptr){
        int var1 = 0, var2 = 0, var3 = 0;
        if (l1 != nullptr){
            var1 = l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr){
            var2 = l2->val;
            l2 = l2->next;
        }

        if (var1 + var2 + addsOn >= 10){
            var3 = var1 + var2 + addsOn - 10;
            addsOn = 1;
        }else{
            var3 = var1 + var2 + addsOn;
            addsOn = 0;
        }
        res = new ListNode(var3);
        res->next = last;
        last = res;
    }
    if (addsOn != 0){
        res = new ListNode(1);
        res->next = last;
    }
    return res;
}
