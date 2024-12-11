/*
Write a Menu Driven Program in C to implement the following operations on an array of integers using functions by passing the array and its size to the function. Populate the array elements using rand( ).
Operations:
1. init()
2. append()
3. insert_at_index()
4. remove_at_index()
5. display()
6. max() /min () // Displays maximum/minimum element of an array
7. reverse() //Reverse the elements of array
8. merge() // Merges two arrays
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

list l = NULL;
int list_index = -1;
void show_menu()
{
	if (l)
		printf("size at the start of show_menu(): %d\n", l->Array->size);
	printf("1. init,2. append, 3. insert_at_index, 4. remove_at_index, 5. display, 6. max /min, 7. reverse, 8. merge");
	if (l)
		printf("size at the end of show_menu(): %d\n", l->Array->size);
}

void read_command(int option, list *l){
	switch (option){
	case 1:{
		array a1;
		int size;
		printf("Enter size of array: ");
		scanf("%d", &size);
		init(&a1, size);
		append_node(l, &a1);
		list_index++;
		printf("list created successfully: %d\n", list_index);
		display_list(*l);
		printf("arr at the end of case 1: %p\n", (*l)->Array->arr);
		return;
	}
	case 2:{
		int data, index, i;
		list p = *l;
		printf("arr at the start of case 2: %p\n", (*l)->Array->arr);
		printf("size in case 2: %d\n", (*l)->Array->size);
		printf("Array no. : ");
		scanf("%d", &index);
		if (index > list_index || index < 0){
			printf("Invalid index! Please try again!\n");
			return;
		}
		i = 0;
		printf("just before loop arr: %p\n", p->Array->arr);
		while (p->next){
			if (i == index){
				break;
			}
			p = p->next;
		}
		printf("just after loop arr: %p\n", p->Array->arr);
		printf("data: ");
		scanf("%d", &data);
		printf("just before append arr: %p\n", p->Array->arr);
		append(p->Array, data);
		printf("Data appended successfully!\n");
		printf("array: ");
		display(*(p->Array));
		break;
	}
	default:
	{
		printf("invalid option");
		return;
	}
	}
}

int main()
{

	init_list(&l);
	if (l == NULL)
		printf("List initialization successful!\n");
	int option;
	while (1)
	{
		if (l)
			printf("size just before show mwenu: %d\n", l->Array->size);
		show_menu();
		if (l)
			printf("size just after show mwenu: %d\n", l->Array->size);
		printf("Enter option: ");
		scanf("%d", &option);
		if (option == 9)
			break;
		read_command(option, &l);
		printf("size in main function : %d\n", l->Array->size);
	}
	/*
		array a1;
		init(&a1, 9		display_list(l);
);
		append(&a1, 5);
	append(&a1, 8);
		insert_at_index(&a1, 4, 90);
	insert_at_index(&a1, 5, 97);
	insert_at_index(&a1, 6, 87);
		// remove_at_index(&a1, 5);
		reverse(&a1);
		max_min(a1);
		display(a1);
		array a1, a2;
		init(&a1, 5);
		init(&a2, 5);
		populate(&a1, 5);
		display(a1);
		populate(&a2, 5);
		display(a2);
		array *a3 = merge(a1, a2);
		display(*a3);
		*/
	return 0;
}
