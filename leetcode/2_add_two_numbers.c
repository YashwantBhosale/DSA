/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// list part

struct ListNode {
	int val;
	struct ListNode* next;
};

void init_list(struct ListNode** l) {
	*l = NULL;
	return;
}


void insertBeg(struct ListNode** head, int d) {
	struct ListNode* nn = newNode();
	nn->val = d;
	nn->next = head;
	*head = nn;
}

void insertEnd(struct ListNode** tail, int d) {
	struct ListNode* nn = newNode();
	nn->val = d;
	nn->next = NULL;
	if (*tail == NULL) {
		*tail = nn;
		return;
	} else {
		(*tail)->next = nn;
		*tail = nn;
	}
	return;
}

// queue part
typedef struct QueueNode {
	int data;
	struct QueueNode* next;
} QueueNode;

typedef struct {
	QueueNode *head, *tail;
} Queue;

void init_q(Queue* q) {
	if (!q)
		return;

	q->head = q->tail = NULL;
	return;
}

void enq(Queue* q, int data) {
	if (!q)
		return;

	QueueNode* nn = (QueueNode*)malloc(sizeof(QueueNode));
	if (!nn)
		return;  // Failed to allocate memory

	nn->data = data;
	nn->next = NULL;

	if (!q->head) {
		q->head = q->tail = nn;
		return;
	}

	q->tail->next = nn;
	q->tail = nn;
	return;
}

int deq(Queue* q) {
	if (!q)
		return INT_MIN;

	if (!q->head)
		return INT_MIN;  // Queue is empty

	QueueNode* temp = q->head;
	int data = temp->data;

	q->head = q->head->next;
	free(temp);
	return data;
}
// above code is unnecessary

struct ListNode* newNode() {
	struct ListNode* nn = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (nn)
		return nn;
	else
		return NULL;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* l = NULL;
	struct ListNode* tail = NULL;
	int carry = 0;

	while (l1 != NULL || l2 != NULL || carry) {
		int d1 = (l1 != NULL) ? l1->val : 0;
		int d2 = (l2 != NULL) ? l2->val : 0;
		int sum = d1 + d2 + carry;

		carry = sum / 10;
		int digit = sum % 10;

		struct ListNode* nn = newNode();
		nn->val = digit;
		nn->next = NULL;

		if (!l) {
			l = nn;
			tail = nn;
		} else {
			tail->next = nn;
			tail = nn;
		}

        /*
        This may not be reommended as we are directly updating the head pointers
        of the list. But here it is ok as we dont need reference to head.
        */
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}

	return l;
}

int main() {
	return 0;
}