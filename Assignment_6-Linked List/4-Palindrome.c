/*
 * Problem-4: Check if the given singly linked list is palindrome or not.
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


bool isPalindrome(struct ListNode* head){
    struct ListNode *curr = head;
    int len = 0, mid, i;

    while(curr != NULL){
        len++;
        curr = curr->next;
    }
    if(len <= 1)
        return true;

    mid = len / 2;
    curr = head;

    int arr[mid];

    for(i = 0; i < mid; i++){
        arr[i] = curr->val;
        curr = curr->next;
    }

    if(len % 2 != 0)
        curr = curr->next;

    for(i = mid - 1; i >= 0; i--){
        if(arr[i] != curr->val)
            return false;
        curr = curr->next;
    }

    return true;
}
