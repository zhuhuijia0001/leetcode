/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) 
{
    if (head == NULL)
    {
        return NULL;
    }
    
    struct ListNode *p, *q;
    
    struct ListNode dummy;
    
    int count = 0;
    
    p = head;
    while (p != NULL)
    {
        count++;
        
        p = p->next;
    }
    
    k %= count;
    
    if (k == 0)
    {
        return head;
    }
    
    dummy.next = head;
    p = &dummy;
    
    q = &dummy;
    
    while (k--)
    {
        p = p->next;
    }
    
    while (p->next != NULL)
    {
        p = p->next;
        
        q = q->next;
    }
    
    struct ListNode *ret;
    ret = q->next;
    
    q->next = p->next;
    p->next = head;
    
    return ret;
}