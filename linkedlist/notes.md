### tip1
需不需要dummy看head会不会被删除

### tip2 
环的入口节点的推理过程
第一次相遇：n = k; 2n = k + 环*整数倍  
k = L(入口) + x(过了入口的距离) = nC  
第二次相遇  
从head开始走L步到入口  
另一个指针 L步 = nC - x 也到入口  

### tip3
进位问题可以使用除数和余数  
```
tail->next = new ListNode(sum_tmp % 10); //ATTENTION
addOn = sum_tmp / 10;
```

### tip4
```
slow->next = slow->next->next; //Memory leak
```
```
ListNode* temp = slow->next;
// 将slow的next指向要删除节点的下一个节点，从而断开链接
slow->next = slow->next->next;
// 释放被删除节点占用的内存
delete temp;
```

### tip5
```    
while(head != nullptr || mid != nullptr){
    if (mid == nullptr || (head != nullptr && head->val < mid->val)){
```