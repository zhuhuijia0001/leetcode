
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *p;
    
    struct ListNode head;
    
    if (l1 == NULL)
    {
        return l2;
    }
    
    if (l2 == NULL)
    {
        return l1;
    }
    
    p = &head;
    
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val > l2->val)
        {
            p->next = l2;
            
            l2 = l2->next;
        }
        else
        {
            p->next = l1;
            
            l1 = l1->next;
        }
        
        p = p->next;
    }
    
    if (l1 != NULL)
    {
        p->next = l1;
    }
    
    if (l2 != NULL)
    {
        p->next = l2;
    }
    
    return head.next;
}