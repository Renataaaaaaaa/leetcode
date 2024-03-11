#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;


ListNode* getMid(ListNode* head){
    ListNode* low = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr){
        low = low->next;
        fast = fast->next->next;
    }
    ListNode* res = low->next;
    low->next = nullptr;
    cout << res->val << endl;
    return res;
}

ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* mid = getMid(head);
    head = sortList(head);
    mid = sortList(mid);
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while(head != nullptr || mid != nullptr){
        if (mid == nullptr || (head != nullptr && head->val < mid->val)){
            tail->next = head;
            head = head->next;
        }else{
            tail->next = mid;
            mid = mid->next;
        }
        tail = tail->next;
    }
    return dummy.next;
}

int main(){
    vector<int> data = {4,2,1,3};
    ListNode* node = generate(data);
    cout << sortList(node)->next->next->val << endl;
}