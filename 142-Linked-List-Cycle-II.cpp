/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) 
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    
    struct ListNode *slow, *fast;
    
    slow = fast = head;
    
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        
        fast = fast->next->next;
        
        if (slow == fast)
        {
            break;
        }
    }
    
    if (slow == fast)
    {
        fast = head;
        
        while (fast != slow)
        {
            fast = fast->next;
            
            slow = slow->next;
        }
        
        return slow;
    }
    
    return NULL;
}