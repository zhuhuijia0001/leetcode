/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head, struct ListNode *tail) 
{
    struct ListNode *p, *q;
    
    if (head == tail || head->next == tail)
    {
        return head;
    }
    
    p = tail;
    
    while (head != tail)
    {
        q = head;
        head = head->next;
        q->next = p;
        p = q;
    }
    
    return q;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) 
{
    struct ListNode *p, *q, *last;
    
    if (head->next == NULL)
    {
        return head;
    }
    
    struct ListNode dummy;
    dummy.next = head;
    
    p = &dummy;
    
    while (m--)
    {
        last = p;
        
        p = p->next;
        n--;
    }
    
    q = p;
    
    while (n--)
    {
        p = p->next;
    }
    
    last->next = reverseList(q, p->next);
    
    return dummy.next;
}
