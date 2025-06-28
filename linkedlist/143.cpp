#include <vector>
#include <iostream>
#include  "utils.cpp"
using namespace std;

ListNode* getMid(ListNode* head){
    ListNode* low = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr){
        low = low->next;
        fast = fast->next->next;
    }
    ListNode* res = low -> next;
    low->next = nullptr;
    return res;
}


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
    ListNode* mid = getMid(head);
    mid = reverseList(mid);
    ListNode* move = head;
    while(move != nullptr &&  mid != nullptr){ //ATTENTION
        ListNode* move_next_old = move->next;
        ListNode* mid_next_old = mid->next;
        move->next = mid;
        mid->next = move_next_old;

        mid = mid_next_old;
        move = move_next_old;
    }
    printLinkedList(head);
}

int main(){
    vector<int> data = {1,2,3};
    ListNode* node = generate(data);
    reorderList(node);
    // cout << node->val << endl;

}