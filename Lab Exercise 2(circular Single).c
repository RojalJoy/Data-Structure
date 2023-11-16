#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct gameNode
{
    struct gameNode *prev;
    struct gameNode *next;
    char title[50]; // Assuming a maximum title length of 50 characters
    int id;         // Game ID
};

struct gameNode *head;

void displayInventory();
void searchGame();
void addGame();
void deleteGame();

void main()
{
    int choice = 0;
    while (choice != 5)
    {
        printf("\n*********Game Store Menu*********\n");
        printf("Choose one option from the following list ...\n");
        printf("===============================================\n");
        printf("1. Add a game\n2. Display inventory\n3. Search for a game\n");
        printf("4. Delete a game\n5. Exit\n");
        printf("Enter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        
        case 1:
            addGame();
            break;
        case 2:
            displayInventory();
            break;
        case 3:
            searchGame();
            break;
        case 4:
            deleteGame();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Please enter a valid choice.\n");
        }
    }
}

void addGame()
{
    struct gameNode *ptr, *temp;
    int gameId;
    char gameTitle[50];

    ptr = (struct gameNode *)malloc(sizeof(struct gameNode));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Game ID: ");
        scanf("%d", &gameId);
        printf("Enter Game Title: ");
        scanf("%s", gameTitle);

        ptr->id = gameId;
        strcpy(ptr->title, gameTitle);

        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
        }
        printf("\nGame added successfully.\n");
    }
}

void deleteGame()
{
    int gameId;
    struct gameNode *ptr, *prevNode, *temp;

    if (head == NULL)
    {
        printf("\nInventory is empty. Nothing to delete.\n");
        return;
    }

    printf("\nEnter Game ID to delete: ");
    scanf("%d", &gameId);

    ptr = head;
    prevNode = NULL;

    while (ptr->id != gameId && ptr->next != head)
    {
        prevNode = ptr;
        ptr = ptr->next;
    }

    if (ptr->id == gameId)
    {
        // Game found, remove it from the inventory
        if (ptr == head && ptr->next == head)
        {
            // Only one game in the inventory
            free(ptr);
            head = NULL;
        }
        else if (ptr == head)
        {
            // Game to be deleted is at the beginning of the inventory
            prevNode = head->prev; // Update the previous node
            temp = head;           // Save the current head
            head = head->next;      // Move head to the next node
            prevNode->next = head;  // Update the previous node's next pointer
            head->prev = prevNode;  // Update the new head's prev pointer
            free(temp);             // Free the memory of the deleted game
        }
        else
        {
            // Game to be deleted is in the middle or at the end of the inventory
            prevNode->next = ptr->next;
            ptr->next->prev = prevNode;
            free(ptr);
        }

        printf("\nGame with ID %d deleted successfully.\n", gameId);
    }
    else
    {
        printf("\nGame with ID %d not found in the inventory.\n", gameId);
    }
}

void displayInventory()
{
    struct gameNode *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\nInventory is empty.\n");
    }
    else
    {
        printf("\nGame Inventory:\n");
        do
        {
            printf("Game ID: %d, Title: %s\n", ptr->id, ptr->title);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

void searchGame()
{
    struct gameNode *ptr;
    int gameId, flag = 0;

    ptr = head;
    if (ptr == NULL)
    {
        printf("\nInventory is empty.\n");
    }
    else
    {
        printf("\nEnter Game ID to search: ");
        scanf("%d", &gameId);

        do
        {
            if (ptr->id == gameId)
            {
                printf("Game found - ID: %d, Title: %s\n", ptr->id, ptr->title);
                flag = 1;
                break;
            }
            ptr = ptr->next;
        } while (ptr != head);

        if (flag == 0)
        {
            printf("Game not found in the inventory.\n");
        }
    }
}

