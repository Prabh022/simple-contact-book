#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"contact.h"

int main() {
	int choice;
	char filename[] = "contacts.txt";
	char searchName[50];
	char newPhone[15];
	while (1) {
		printf("\n---Contact Book---\n");
		printf("1. Add Contact\n");
		printf("2. View all Contacts\n");
		printf("3. Search Contact by Name\n");
		printf("4. Delete Contact\n");
		printf("5. Edit Contact\n");
		printf("6. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		
		switch (choice)
		{
		case 1:
			addContact(filename);
			break;

		case 2:
			viewContact(filename);
			break;

		case 3:
			printf("Enter the name to Search: ");
			scanf(" %[^\n]", searchName);
			searchContact(filename, searchName);
			break;

		case 4:
			printf("Enter the name to Delete: ");
			scanf(" %[^\n]", searchName);
			deleteContact(filename, searchName);
			break;

		case 5:
			printf("Enter the name to Edit: ");
			scanf(" %[^\n]", searchName);
			printf("Enter the new phone: ");
			scanf(" %14[^\n]", newPhone);
			editContact(filename, searchName, newPhone);
			break;

		case 6:
			printf("Exiting... \n");
			exit(0);
		default:
			printf("Invalid Choice\n");
		}
	}

	return 0;
}