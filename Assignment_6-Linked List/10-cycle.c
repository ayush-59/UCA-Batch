/*
 * Problem-10: Return the node from where cycle begins, if cycle exists, in the singly linked list.
 * Ayush Singh 1910990059 27/08/21
 * Assignment_6 -> Linked List
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL)
        return NULL;

    struct ListNode *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }

    if(slow != fast)
        return NULL;

    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
