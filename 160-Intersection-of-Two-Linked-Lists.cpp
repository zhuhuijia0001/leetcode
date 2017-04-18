/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    
    struct ListNode *pA, *pB;
    
    int countA = 0;
    pA = headA;
    pB = headB;
    
    while (pA != NULL)
    {
        countA++;
        
        pA = pA->next;
    }
    
    int countB = 0;
    while (pB != NULL)
    {
        countB++;
        
        pB = pB->next;
    }
    
    pA = headA;
    pB = headB;
    while (countA > countB)
    {
        pA = pA->next;
        
        countA--;
    }
    
    while (countB > countA)
    {
        pB = pB->next;
        
        countB--;
    }
    
    while (pA != NULL)
    {
        if (pA == pB)
        {
            return pA;
        }
        
        pA = pA->next;
        pB = pB->next;
    }
    
    return NULL;
}