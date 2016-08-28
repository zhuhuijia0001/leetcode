/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode *fast = head;
    
    struct ListNode *slow = &dummy;
    
    while (n--)
    {
        fast = fast->next;
    }
    
    while (fast != NULL)
    {
        fast = fast->next;
        
        slow = slow->next;
    }
    
    fast = slow->next;
    slow->next = slow->next->next;
    free(fast);
    
    return dummy.next;
}