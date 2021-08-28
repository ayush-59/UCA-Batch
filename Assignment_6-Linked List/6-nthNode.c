/*
 * Problem-6: Remove Nth node from list
 * Ayush Singh 1910990059 19/08/21
 * Assignment_6 -> Linked List
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *slow = head, *fast = head, *temp;


    while(n--){
        fast = fast->next;
    }
    if(fast == NULL){
        return head->next;

    }
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    temp = slow->next;
    if(temp->next == NULL){
        slow->next = NULL;
    }
    else{
        slow->next = temp->next;
    }

    return head;
}
