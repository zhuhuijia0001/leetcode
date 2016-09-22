/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) 
{
    struct ListNode dummy;
    
    struct ListNode *p, *p_prev, *q;
    
    dummy.next = head;
    
    p = dummy.next;
    p_prev = &dummy;
    
    while (p != NULL)
    {
        q = &dummy;
        
        while (q->next != p && q->next->val <= p->val)
        {
            q = q->next;
        }
        
        if (p != q->next)
        {
            p_prev->next = p->next;
            
            p->next = q->next;
            
            q->next = p;
            
            p = p_prev->next;
        }
        else
        {
            p_prev = p;
            
            p = p->next;
        }
    }
    
    return dummy.next;
}