#include <stdio.h>
#include <stdlib.h>

/* List ADT and functions */
struct ListNode {
    int val;
    struct ListNode *next;
};

void init_list(struct ListNode **l) {
    *l = NULL;
    return;
}

void append(struct ListNode **l, int val) {
    struct ListNode *nn = (struct ListNode *) malloc(sizeof(struct ListNode));
    nn -> val = val;
    nn -> next = NULL;  
    if(!(*l)) {
        *l = nn;
    } else {
        struct ListNode *p = *l;
        while(p -> next) {
            p = p -> next;
        }
        p -> next = nn;
    }
    return;
}

void display_list(struct ListNode *l) {
    struct ListNode *p = l;
    printf("[\t");
    while(p) {
        printf("%d\t", p -> val);
        p = p -> next;
    }
    printf("]\n");
    return;
}
/* End of list ADT */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(!list1)
        return list2;
    else if(!list2)
        return list1;

    struct ListNode *head = NULL, *p=list1, *q=list2, *tail=NULL;
    head = list1->val < list2->val ? list1 : list2;
    tail = head;
    if (tail == p) {
        p = p->next;
    }else {
        q = q->next;
    }
    while(p && q) {
        if(p->val < q->val) {
            tail -> next = p;
            tail = p;
            p = p->next;
        }else {
            tail -> next = q;
            tail = q;
            q = q->next;
        }
    }
    while(q) {
        tail -> next = q;
        tail = q;
        q = q->next;
    }
    while(p) {
        tail -> next = p;
        tail = p;
        p = p -> next;
    }
    return head;
}

int main() {
    struct ListNode *l1, *l2, *l3;
    init_list(&l1);
    init_list(&l2);
    append(&l1, 1);
    append(&l1, 2);
    append(&l1, 4);
    display_list(l1);

    append(&l2, 1);
    append(&l2, 3);
    append(&l2, 4);
    display_list(l2);
    
    l3 = mergeTwoLists(l1, l2);
    display_list(l3);
    return 0;
}
