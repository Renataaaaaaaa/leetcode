/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* sortList(vector<ListNode*>& lists, int i, int j) {
    if (i == j){
        return lists[i];
    }
    int mid = (i + j) / 2;
    ListNode* left = sortList(lists, i, mid);
    ListNode* right = sortList(lists, mid + 1, j);

    ListNode* res = new ListNode();
    ListNode* move = res;
    while(left != nullptr || right != nullptr){
        if (right == nullptr || (left != nullptr && left ->val < right->val)){
            move->next = left;
            left = left->next;
        }else{
            move->next = right;
            right = right->next;
        }
        move = move->next;
    }
    return res->next;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0){
        return nullptr;
    }
    return sortList(lists, 0, lists.size() - 1);
}
};