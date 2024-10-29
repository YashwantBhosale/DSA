#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// This solution was directly accepted without testing locally so no template code in main

struct ListNode {
	int val;
	struct ListNode* next;
};

void swap(struct ListNode *p, struct ListNode *q, struct ListNode *r) {
    // r is suppposed to be the previous node of p
    if(r)
        r->next = q;
    p->next = q->next;
    q->next = p;
    return;
}

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p, *q, *r, *newHead;

    p = head;

    if(!p || p->next == NULL){
        return p;
    }

    q = p->next;
    newHead = q;
    r = NULL;
    while(p && q) {
        swap(p, q, r);
        r = p;
        p = p->next;
        if(!p)
            break;
        q = p->next;

    }

    return newHead;
}

int main() {
	printf("Hello world!\n");

	return 0;
}