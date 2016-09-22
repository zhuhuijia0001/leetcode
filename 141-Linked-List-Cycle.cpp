/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }
        
        ListNode *fast, *slow;
        
        fast = head;
        slow = fast;
        
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            
            slow = slow->next;
            
            if (slow == fast)
            {
                break;
            }
        }
        
        return slow == fast;
    }
};