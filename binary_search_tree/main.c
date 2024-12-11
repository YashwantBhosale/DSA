#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void displayMenu() {
	printf("1. Insert\n");
	printf("2. Remove\n");
	printf("3. Display\n");
	printf("4. Destroy\n");
	printf("5. Exit\n");
	return;
}

void evaluate_choice(int choice, bst *tree) {
	int month;
	switch (choice) {
		case 1:
			printf("Please Enter number between 1 and 12\n");
			printf("{ 1: January, 2: February, 3: March, 4: April, 5: May, 6: June, 7: July, 8: August, 9: September, 10: October, 11: November, 12: December }\n");
			
            printf("Enter the month: ");
			scanf("%d", &month);

			if (month < 1 || month > 12) {
				printf("Invalid month\n");
				break;
			}

			insertNode(tree, month - 1);
			break;
		case 2:
            printf("Please Enter number between 1 and 12\n");
			printf("{ 1: January, 2: February, 3: March, 4: April, 5: May, 6: June, 7: July, 8: August, 9: September, 10: October, 11: November, 12: December }\n");
			
            printf("Enter the month: ");
			scanf("%d", &month);

			if (month < 1 || month > 12) {
				printf("Invalid month\n");
				break;
			}
			removeNode(tree, month-1);
			break;
		case 3:
			inorder(tree);
			break;
		case 4:
			destroyTree(tree);
			break;
		case 5:
			exit(0);
		default:
			printf("Invalid choice\n");
	}
	return;
}

int main() {
	bst tree;
	init_bst(&tree);

	int choice;

	while (1) {
		displayMenu();
		printf("Enter your choice: ");
		scanf("%d", &choice);
		evaluate_choice(choice, &tree);
	}

	return 0;
}