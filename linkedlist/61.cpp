#include <vector>
#include <iostream>
#include "utils.cpp"
using namespace std;

ListNode* rotateRight(ListNode* head, int k) {

    if (head == nullptr || k < 1 || head->next == nullptr){
        return head;
    }
    ListNode* iter = head;
    int num = 1;
    while(iter->next != nullptr){
        iter=iter->next;
        num++;
    }
    ListNode* end = iter;

    if (k % num == 0){
        return head;
    }
    k = (num - (k % num)) - 1;
    iter = head;
    for (int i = 0; i < k ; i++){
        iter = iter->next;
    }
    ListNode* next = iter->next;
    iter->next = nullptr;
    end->next = head;
    return next;
}

int main(){
    vector<int> data = {1,2};
    printLinkedList(rotateRight(generate(data), 1));
}