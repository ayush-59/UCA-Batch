/*
 * Problem-8: Merge two Sorted List
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


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *mergedList, *curr;

    if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;

    if(l1->val <= l2->val){
        mergedList = l1;
        l1 = l1->next;
    }
    else{
        mergedList = l2;
        l2 = l2->next;
    }

    curr = mergedList;

    while(l1 != NULL && l2 != NULL){
        if(l1->val <= l2->val){
            curr->next = l1;
            curr = curr->next;
            l1 = l1->next;
        }
        else{
            curr->next = l2;
            curr = curr->next;
            l2 = l2->next;
        }
    }
    while(l1 != NULL){
        curr->next = l1;
        curr = curr->next;
        l1 = l1->next;
    }
    while(l2 != NULL){
        curr->next = l2;
        curr = curr->next;
        l2 = l2->next;
    }

    return mergedList;


}
