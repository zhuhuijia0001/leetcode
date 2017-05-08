/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) 
{
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode *p = &dummy;
    
    while (p != NULL && p->next != NULL)
    {
        if (p->next->val == val)
        {
            struct ListNode *tmp = p->next;
            p->next = p->next->next;
            
            free(tmp);
        }
        else
        {
            p = p->next;
        }
    }
    
    return dummy.next;
}