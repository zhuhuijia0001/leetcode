/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode *reverse(struct ListNode *head, struct ListNode *tail)
{
    struct ListNode *p, *q;
    struct ListNode *t = tail->next;

    q = NULL;
    while (head != t)
    {
        p = head;
        
        head = head->next;
        
        p->next = q;
        
        q = p;
    }
    
    return p;
}

bool isPalindrome(struct ListNode* head) 
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode *slow, *fast;
    slow = fast = &dummy;
    
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        
        fast = fast->next->next;
    }
    
    struct ListNode *p, *q;
    q = slow->next;
    p = reverse(head, slow);
    if (fast == NULL)
    {
        //odd
        p = p->next;
    }
    
    while (p != NULL)
    {
        if (p->val != q->val)
        {
            break;
        }
        
        p = p->next;
        q = q->next;
    }
    
    return p == NULL;
}