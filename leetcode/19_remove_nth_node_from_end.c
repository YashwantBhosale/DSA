/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// This was directly submitted on leetcode without testing
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	int len = 0;
	struct ListNode *p, *q, *delete;
	q = p = head;
	while (q->next) {
		len++;
		q = q->next;
	}

    if(n-len == 1) {
        struct ListNode *temp = head;
        head = temp ? temp -> next : NULL;
        free(temp);
        return head;
    }

	while (len != n && p) {
		p = p->next;
		len--;
	}

	delete = p ? p->next : NULL;
	if (delete) {
		p->next = delete->next;
		free(delete);
	}

	return head;
}