#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list l;
int list_ptr = -1;
void view_menu(){
    printf("\n------------------------------------------\n");
    printf("1. init\n2. append\n3. insert_at_index\n4. remove_at_index\n5. display\n6. max /min\n7. reverse\n8. merge\n");
    printf("\n ------------------------------------------\n");
}

void read_option(int option) {
    switch(option) {
        case 1: {
            int size;
            array *a = (array *) malloc(sizeof(array));
            printf("Enter size: ");
            scanf("%d", &size);
            init(a, size);
            append_node(&l, a);
            list_ptr++;
            return;
            break;
        }case 2: {
            int index, data;
            node *p;
            printf("Enter array no.: ");
            scanf("%d", &index);
            while((index-1) > list_ptr ){
                printf("Enter array no.: ");
                scanf("%d", &index);
            }
            p = l;
            while(p->next && index-1) {
                p = p->next;
                index--;
            }
            printf("Enter data: ");
            scanf("%d", &data);
            append(p->A, data);
            return;
            break;
        }case 3: {
            node* p;
            int data, index, array;
            printf("Array no.: ");
            scanf("%d", &array);
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter index: ");
            scanf("%d", &index);
            p = l;
            int i = 0;
            while(p->next && i < array) {
                p = p->next;
                i++;
            }
            insert_at_index(p->A, index, data);
            return;
        }case 4: {
            node* p;
            int index, array;
            printf("Array no.: ");
            scanf("%d", &array);
            printf("Enter index: ");
            scanf("%d", &index);
            p = l;
            int i = 0;
            while(p->next && i < array) {
                p = p->next;
                i++;
            }
            remove_at_index(p->A, index);
            return;
        }case 5: {
            node *p;
            int array, i =0;
            printf("Array no: ");
            scanf("%d", &array);
            p = l;
            while(p->next && i < array) {
                p = p->next;
                i++;
            }
            display(*(p->A));
            return;
        }case 6: {            
            node *p;
            int array, i =0;
            printf("Array no: ");
            scanf("%d", &array);
            p = l;
            while(p->next && i < array) {
                p = p->next;
                i++;
            }
            max_min(*(p->A));
        }
        case 7: {
            int index;
            node *p;
            printf("Enter array no.: ");
            scanf("%d", &index);
            while((index-1) > list_ptr ){
                printf("Enter array no.: ");
                scanf("%d", &index);
            }
            p = l;
            while(p->next && index-1) {
                p = p->next;
                index--;
            }
            reverse(p->A);
            return;       
        }case 8:{
            
        }
        case 9: {
            return;
        }
        case 10: {
            int index;
            node *p;
            printf("Enter array no.: ");
            scanf("%d", &index);
            while((index-1) > list_ptr ){
                printf("Enter array no.: ");
                scanf("%d", &index);
            }
            p = l;
            while(p->next && index-1) {
                p = p->next;
                index--;
            }
            populate(p->A, p->A->size);
            return;
        }
        default: {
            printf("invalid option!\n");
            break;
        }
    }
}

int main(){
    int option;
    init_list(&l);
    while(1){
        view_menu();
        printf("enter option: ");
        scanf("%d", &option);
        read_option(option);
        if(option == 9){
            break;
        }
        display_list(l);
    }
    return 0;
}