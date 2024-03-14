#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while(list1 != nullptr || list2 != nullptr){
        if (list1 == nullptr || ( list2 != nullptr && list2->val < list1->val)){
            tail->next = list2;
            list2 = list2->next;
        }else{
            tail->next = list1;
            list1 = list1->next;
        }
        tail = tail->next;
    }
    return dummy.next;
}

int main(){
    vector<int> data_1 = {};
    vector<int> data_2 = {0};
    ListNode* node1 = generate(data_1);
    ListNode* node2 = generate(data_2);
    printLinkedList(mergeTwoLists(node1, node2));
}