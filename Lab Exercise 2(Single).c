#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>

struct node   
{  
    int id;  
    char title[50];
    struct node *next;   
};

struct node *head;

void beginsert();   
void lastinsert();  
void randominsert();  
void begin_delete();  
void last_delete();  
void random_delete();  
void display();  
void search();  

void main()  
{  
    int choice = 0;  
    while(choice != 9)   
    {  
        printf("\n\n********* Main Menu *********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1. Add a game to the beginning\n2. Add a game at last\n3. Add a game at any random location\n");
        printf("4. Delete a game from beginning\n5. Delete a game from last\n6. Delete a game from a specified location\n");
        printf("7. Search a game \n8. Show\n9. Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("%d", &choice);  
        switch(choice)  
        {  
            case 1:  
                beginsert();      
                break;  
            case 2:  
                lastinsert();         
                break;  
            case 3:  
                randominsert();       
                break;  
            case 4:  
                begin_delete();       
                break;  
            case 5:  
                last_delete();        
                break;  
            case 6:  
                random_delete();          
                break;  
            case 7:  
                search();         
                break;  
            case 8:  
                display();        
                break;  
            case 9:  
                exit(0);  
                break;  
            default:  
                printf("Please enter a valid choice.\n");  
        }  
    }  
}  

void beginsert()  
{  
    struct node *ptr;  
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter ID: ");    
        scanf("%d", &(ptr->id));  

        printf("Enter title: ");    
        scanf("%s", ptr->title);  

        ptr->next = head;  
        head = ptr;  
        printf("\nNode inserted");  
    }  
}  

void lastinsert()  
{  
    struct node *ptr, *temp;  
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter ID: ");  
        scanf("%d", &(ptr->id));  

        printf("Enter title: ");  
        scanf("%s", ptr->title);  

        if(head == NULL)  
        {  
            ptr->next = NULL;  
            head = ptr;  
            printf("\nNode inserted");  
        }  
        else  
        {  
            temp = head;  
            while (temp->next != NULL)  
            {  
                temp = temp->next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
            printf("\nNode inserted");  
        }  
    }  
}  

void randominsert()  
{  
    int i, loc;   
    struct node *ptr, *temp;  
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter ID: ");  
        scanf("%d", &(ptr->id));  

        printf("Enter title: ");  
        scanf("%s", ptr->title);  

        printf("\nEnter the location after which you want to insert: ");  
        scanf("%d", &loc);  
        temp = head;  
        for(i = 0; i < loc; i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
        }  
        ptr->next = temp->next;   
        temp->next = ptr;   
        printf("\nNode inserted");  
    }  
}  

void begin_delete()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        printf("\nNode deleted from the beginning...\n");  
    }  
}  

void last_delete()  
{  
    struct node *ptr, *ptr1;  
    if(head == NULL)  
    {  
        printf("\nList is empty");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted...\n");  
    }  
    else  
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("\nDeleted Node from the last...\n");  
    }     
}  

void random_delete()  
{  
    struct node *ptr, *ptr1;  
    int loc, i;    
    printf("\nEnter the location of the node after which you want to perform deletion: ");  
    scanf("%d", &loc);  
    ptr = head;  
    for(i = 0; i < loc; i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1->next = ptr->next;  
    free(ptr);  
    printf("\nDeleted node %d\n", loc + 1);  
}  

void search()  
{  
    struct node *ptr;  
    int searchId, i = 0, flag=1;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter ID which you want to search: ");   
        scanf("%d", &searchId);  
        while (ptr != NULL)  
        {  
            if(ptr->id == searchId)  
            {  
                printf("Game found at location %d\n", i + 1); 
				printf("Id :%d Title:%s",ptr->id,ptr->title) ;
                flag = 0;  
            }   
            i++;  
            ptr = ptr->next;  
        }  
        if(flag == 1)  
        {  
            printf("Game not found\n");  
        }  
    }     
}  

void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print\n");  
    }  
    else  
    {  
        printf("\nPrinting values . . . . .\n");   
        while (ptr != NULL)  
        {  
            printf("\nID: %d\n", ptr->id);  
            printf("Title: %s\n", ptr->title);  
            ptr = ptr->next;  
        }  
    }  
}  

