/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    //Returns the node if it's last in the list or if it doesn't exist
    if (head == NULL || head->next == NULL) {
        return head;
    }
    //Recurses through the last starting from the back
    struct ListNode* newHead = reverseList(head->next);
    //Sets the second to last node to point the the current header (which should be the last node)
    //i.e. making 5 point to 4
    head->next->next = head;
    //Makes the last node (the current head) point to null
    //i.e. making 1 point to null instead of 2
    head->next = NULL;
    //returns the end header (i.e. 5 in the example)
    return newHead;
}
