#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* move = &dummy;
    while(move != nullptr && move->next != nullptr){
        if (move->next->val == val){
            ListNode* tmp = move->next->next;
            move->next = nullptr;
            move->next = tmp;
        }else{
            move = move->next;
        }
        
    }
    return dummy.next;
}

int main(){
    vector<int> data = {6,5,6};
    ListNode* head = generate(data);
    cout << removeElements(head, 6)->val << endl;
}