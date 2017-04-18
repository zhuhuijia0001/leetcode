/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) 
{
    struct ListNode *p;
    p = head;
    
    struct ListNode dummy1, dummy2;
    struct ListNode *tail1, *tail2;
    
    dummy1.next = NULL;
    dummy2.next = NULL;
    
    tail1 = &dummy1;
    tail2 = &dummy2;
    
    while (p != NULL)
    {
        if (p->val < x)
        {
            tail1->next = p;
            tail1 = tail1->next;
        }
        else
        {
            tail2->next = p;
            tail2 = tail2->next;
        }
        
        p = p->next;
    }
    
    tail1->next = dummy2.next;
    tail2->next = NULL;
    
    return dummy1.next;
}