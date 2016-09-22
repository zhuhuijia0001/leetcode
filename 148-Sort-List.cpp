/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
static struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
	struct ListNode *p;

	struct ListNode head;

	if (l1 == NULL)
	{
		return l2;
	}

	if (l2 == NULL)
	{
		return l1;
	}

	p = &head;

	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val > l2->val)
		{
			p->next = l2;

			l2 = l2->next;
		}
		else
		{
			p->next = l1;

			l1 = l1->next;
		}

		p = p->next;
	}

	if (l1 != NULL)
	{
		p->next = l1;
	}

	if (l2 != NULL)
	{
		p->next = l2;
	}

	return head.next;
}

struct ListNode* sortList(struct ListNode* head) 
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	struct ListNode *fast, *slow;
	struct ListNode dummy;
	dummy.next = head;
	fast = &dummy;
	slow = &dummy;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;

		slow = slow->next;
	}

	fast = slow->next;
	slow->next = NULL;

	head = sortList(head);

	fast = sortList(fast);

	return mergeTwoLists(head, fast);
}