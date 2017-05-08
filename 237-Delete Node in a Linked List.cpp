/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) 
{
    while (node->next != NULL)
    {
        node->val = node->next->val;
        
        if (node->next->next == NULL)
        {
            node->next = NULL;
        }
        else
        {
            node = node->next;
        }
    }
}