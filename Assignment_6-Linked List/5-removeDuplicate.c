/*
 * Problem-5: Remove Duplicates from a sorted Linked List
 * Ayush Singh 1910990059 26/08/21
 * Assignment_6 -> Linked List
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *curr = head, *prev = NULL, *newHead = NULL, *node = NULL;

    if(head == NULL || head->next == NULL)
        return head;

    while(newHead == NULL && curr != NULL){
        if((prev == NULL || prev->val != curr->val) && (curr->next == NULL || curr->next->val != curr->val)){
            newHead = curr;
            node = newHead;



        }
        prev = curr;
        curr = curr->next;
    }
    if(newHead != NULL)
        newHead->next = NULL;


    while(curr != NULL){
        if((prev == NULL || prev->val != curr->val) && (curr->next == NULL || curr->next->val != curr->val)){
            printf("%d ",curr->val);
            node->next = curr;
            node = node->next;
        }
        prev = curr;
        curr = curr->next;
    }
    if(node != NULL)
        node->next = NULL;

    return newHead;

}
