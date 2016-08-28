/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    struct ListNode *p, *q;
    
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    q = head;
    p = head->next;
    
    while (p != NULL)
    {
        while (p->val == q->val)
        {
            struct ListNode *tmp = p;
            p = p->next;
            
            free(tmp);
            
            if (p == NULL)
            {
                break;
            }
        }
 
        q->next = p;
            
        q = q->next;
        
        if (p != NULL)
        {
            p = p->next;
        }
    }
    
    return head;
}