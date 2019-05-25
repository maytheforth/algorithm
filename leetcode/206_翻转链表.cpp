class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if((head == NULL) || (head->next == NULL))
           return head;
        
        ListNode* first = reverseList(head->next);
        head->next->next = head;  //这里解释一下
        head->next = NULL;
        
        return first;
    }
};
