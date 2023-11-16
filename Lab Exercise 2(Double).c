#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game {
    int id;
    char title[50];
};

struct node {
    struct node *prev;
    struct node *next;
    struct game data;
};

struct node *head;

void insertion_last();
void deletion_specified();
void display();
void search();

void main() {
    int choice = 0;
    while (choice != 5) {
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1. Add a game to the inventory\n2. Delete a game\n3. Display all games \n4. Search a game\n5. Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice) {
            case 1:
                insertion_last(); // Add a game to the inventory
                break;
            case 2:
                deletion_specified(); // Delete a game
                break;
            case 3:
                display(); // Display all games
                break;
            case 4:
                search(); // Search for a game
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Please enter a valid choice..");
        }
    }
}

void insertion_last() {
    struct node *ptr, *temp;
    int id;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter game ID: ");
        scanf("%d", &id);
        printf("Enter game title: ");
        scanf("%s", ptr->data.title);
        ptr->data.id = id;
        if (head == NULL) {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
        printf("\nGame added to the inventory\n");
    }
}

void deletion_specified() {
    struct node *ptr, *temp;
    int id;
    printf("\nEnter the game ID to delete: ");
    scanf("%d", &id);
    ptr = head;

    while (ptr != NULL) {
        if (ptr->data.id == id) {
            if (ptr->prev == NULL) {
                head = ptr->next;
                head->prev = NULL;
                free(ptr);
            } else {
                temp = ptr->prev;
                temp->next = ptr->next;
                if (ptr->next != NULL) {
                    ptr->next->prev = temp;
                }
                free(ptr);
            }
            printf("\nGame with ID %d deleted\n", id);
            return;
        }
        ptr = ptr->next;
    }

    printf("\nGame with ID %d not found\n", id);
}

void display() {
    struct node *ptr;
    printf("\nPrinting game inventory...\n");
    ptr = head;

    while (ptr != NULL) {
        printf("ID: %d, Title: %s\n", ptr->data.id, ptr->data.title);
        ptr = ptr->next;
    }
}

void search() {
    struct node *ptr;
    int id;
    printf("\nEnter the game ID to search: ");
    scanf("%d", &id);
    ptr = head;

    while (ptr != NULL) {
        if (ptr->data.id == id) {
            printf("\nGame found - ID: %d, Title: %s\n", ptr->data.id, ptr->data.title);
            return;
        }
        ptr = ptr->next;
    }

    printf("\nGame with ID %d not found\n", id);
}

