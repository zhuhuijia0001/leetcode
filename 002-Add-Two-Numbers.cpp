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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int c;
        
        ListNode *head = NULL;
        ListNode *tail;
        ListNode *p;
        c = 0;
        while (l1 != NULL && l2 != NULL)
        {
            c += l1->val + l2->val;
            if (c >= 10)
            {
                p = new ListNode(c - 10);
                
                c = 1;
            }
            else
            {
                p = new ListNode(c);
                
                c = 0;
            }
            
            if (head == NULL)
            {
                head = tail = p;
            }
            else
            {
                tail->next = p;
                tail = tail->next;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != NULL)
        {
            c += l1->val;
            if (c >= 10)
            {
                p = new ListNode(c - 10);
                
                c = 1;
            }
            else
            {
                p = new ListNode(c);
                
                c = 0;
            }
            
            tail->next = p;
            tail = tail->next;
            
            l1 = l1->next;
        }
        
        while (l2 != NULL)
        {
            c += l2->val;
            if (c >= 10)
            {
                p = new ListNode(c - 10);
                
                c = 1;
            }
            else
            {
                p = new ListNode(c);
                
                c = 0;
            }
            
            tail->next = p;
            tail = tail->next;
            
            l2 = l2->next;
        }
        
        if (c > 0)
        {
            p = new ListNode(1);
            
            tail->next = p;
        }
        
        return head;
    }
};