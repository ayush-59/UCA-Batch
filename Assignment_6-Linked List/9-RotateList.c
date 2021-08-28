/*
 * Problem-9: Rotate a Linked List
 * Ayush Singh 1910990059 24/08/21
 * Assignment_6 -> Linked List
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode *slow = head, *fast = head, *temp;

    if(head == NULL)
        return NULL;
    else if(head->next == NULL)
        return head;

    for(int i = 1; i <= k; i++){
        fast = fast->next;
        if(fast == NULL){
            fast = head;
            k = k % i;
            i = 0;
        }

    }
    if(slow == fast)
        return head;

    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;

    }

    temp = slow->next;
    slow->next = NULL;
    fast->next = head;

    return temp;
}
