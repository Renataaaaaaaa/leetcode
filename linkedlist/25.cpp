
#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

bool checkSize(ListNode* head, int range){
    int i = 0;
    while(head != nullptr){
        head = head->next;
        i++;
    }
    if (i >= range){
        return true;
    }else{
        return false;
    }
}
pair<ListNode*, ListNode*> reverseList(ListNode* head, int range){
    

    ListNode* prev = nullptr;
    ListNode* next_tmp = nullptr;
    int i = 0;
    for (i = 0; i < range; i++){
        next_tmp = head->next;
        head->next = prev;
        prev = head;
        head = next_tmp;
        // printLinkedList(head);
    }
    return make_pair(prev, head);
    
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* move = &dummy;
    ListNode* tmp = nullptr;
    while(move != nullptr && move->next != nullptr){
        if (!checkSize(move->next, k)){
            break;
        }
        tmp = move->next;
        pair<ListNode*, ListNode*> pairRes = reverseList(move->next, k);
        // cout << pairRes.first->val << " " << pairRes.second->val << endl;
        
        move->next->next = pairRes.second; //ATTENTION
        move->next = pairRes.first;
        
        move = tmp;
        // printLinkedList(move);
        cout << "38" << endl;
    }
    return dummy.next;

}
int main(){
    vector<int> data = {1,2,3,4,5};
    ListNode* node = generate(data);
    printLinkedList(reverseKGroup(node, 2));
}