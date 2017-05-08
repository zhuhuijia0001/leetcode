/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverseInternal(head);
    }
    
private:
    ListNode *reverseInternal(ListNode *t) {
        if (t == nullptr || t->next == nullptr) {
            return t;
        }
        
        ListNode *res = reverseInternal(t->next);
        t->next->next = t;
        
        t->next = nullptr;
        
        return res;
    }
};