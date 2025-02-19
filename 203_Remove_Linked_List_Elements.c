/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
In this problem we had to remove every one of a
specified value from a linked list
i.e. In the list 1, 2, 3, 4, 3, 8 with a value of 3,
the final list would be 1, 2, 4, 8
*/
struct ListNode* removeElements(struct ListNode* head, int val) {
    //Create a node to hold the head
    struct ListNode holder;
    //Sets the next to head so I don't have to do an edge case
    holder.next = head;
    //Makes a pointer to traverse the list
    struct ListNode* cur = &holder;
    //Traverses the list
    while (cur->next != NULL) {
        //Check if the next node needs to be removed
        if (cur->next->val == val) {
            //If it does, initialize a pointer to the node that gets removed
            struct ListNode* temp = cur->next;
            //Delete a node by skipping it
            cur->next = temp->next;
        } 
        else {
            //Otherwise just move on
            cur = cur->next;
        }
    }
    //Returns the final list, if the former head is removed then this will still work
    return holder.next;
}
