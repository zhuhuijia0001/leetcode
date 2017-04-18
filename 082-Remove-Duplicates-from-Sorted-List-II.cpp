/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	struct ListNode dummy;
	dummy.next = head;

	struct ListNode *p, *q;

	q = &dummy;
	p = head->next;

	bool duplicated = false;

	while (p != NULL)
	{
		if (q->next->val == p->val)
		{
			struct ListNode *tmp = q->next;
			q->next = q->next->next;

			free(tmp);

			duplicated = true;
		}
		else
		{
			if (duplicated)
			{
				struct ListNode *tmp = q->next;
				q->next = q->next->next;

				free(tmp);

				duplicated = false;
			}
			else
			{
			    q = q->next;
			}
		}

		p = p->next;
	}

	if (duplicated)
	{
		struct ListNode *tmp = q->next;
		q->next = q->next->next;

		free(tmp);
	}

	return dummy.next;
}