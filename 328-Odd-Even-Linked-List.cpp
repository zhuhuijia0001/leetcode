/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) 
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    struct ListNode *p, *q, *tmp;
    
    p = head;
    tmp = q = head->next;
    
    while (q!= NULL && q->next != NULL)
    {
        p->next = q->next;
        p = p->next;
        
        q->next = p->next;
        q = q->next;
    }
    
    p->next = tmp;
    
    return head;
}