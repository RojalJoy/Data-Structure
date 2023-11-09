#include <stdio.h>
#include <conio.h>
struct Games {
    char name[50];
    int prices[3][1];
	int playtime[3][1];
};

//For entering a new value
void get(struct Games *g1){
int i,j,k;

        printf("Enter the name of the game: ");
        scanf("%s", g1[i].name);
        printf("Enter its price in PS,PC and Mobile respec : ");

        for (j = 0; j < 3; j++) {
  
            scanf("%d", &g1[i].prices[j][0]);

        }
        printf("Enter its playtime in PS,PC and Mobile respec : ");

        for (k = 0; k < 3; k++) {
  
            scanf("%d", &g1[i].playtime[k][0]);
        }
    
}

// For displaying new values
void priceDisplay(struct Games *g1)
{
	int j,i;
    for(j=0;j<3;j++)
    {	printf("\t%d",g1->prices[j][0]);	}
		
}

void ptDisplay(struct Games *g1)
{
	int j;
	for(j=0;j<3;j++)
    {	printf("\t%d",g1->playtime[j][0]);	}
}

void delPrice(struct Games *g1,int r1,int c1,int size)
{
	int r=r1,i,c=c1;
	if (r >= 0 && r < 2 && c >= 0 && c < 3) {
        g1[r].prices[c][0] = 0;
        printf("Element deleted.\n");
    } else {
        printf("Invalid indices. Element not deleted.\n");
    }
	printf("The prices : \n");
    for (i = 0; i < size; i++) {
        priceDisplay(&g1[i]);
        printf("\n");
    }
		
}
void delPlay(struct Games *g1,int r1,int c1,int size)
{
	int r=r1,i,c=c1;
	if (r >= 0 && r < 2 && c >= 0 && c < 3) {
        g1[r].playtime[c][0] = 0;
        printf("Element deleted.\n");
    } else {
        printf("Invalid indices. Element not deleted.\n");
    }
	printf("The Playtime: \n");
    for (i = 0; i < size; i++) {
        ptDisplay(&g1[i]);
        printf("\n");
    }
		
}

void linearSearchPrice(struct Games *g1,int value,int size )
{
 int index = 0,i,j;

    for ( i = 0; i < size; i++) {
        for (j = 0; j < 3; j++) {
            if (g1[i].prices[j][0] == value) {
                index = 1;
                break;
            }
        }
    }

    if (index == 1) {
        printf("The price is there\n");
    } else {
        printf("The price is not there\n");
    }
}

void linearSearchPlay(struct Games *g1,int value,int size )
{
 int index = 0,i,j;

    for ( i = 0; i < size; i++) {
        for (j = 0; j < 3; j++) {
            if (g1[i].playtime[j][0] == value) {
                index = 1;
                break;
            }
        }
    }

    if (index == 1) {
        printf("The entered playtime is there\n");
    } else {
        printf("The entered playtime is not there\n");
    }
}

// To add price and playtime matrices
void addMatrices(struct Games *g1, int size) 
{
	int i,j;
    for ( i = 0; i < size; i++) {
        for (j = 0; j < 3; j++) {
            printf("\t%d", g1[i].prices[j][0] + g1[i].playtime[j][0]);
        }
        printf("\n");
    }
}

// To multiply price and playtime matrices
void multiplyMatrices(struct Games *g1, int size)
 {
 	int i,j;
    for ( i = 0; i < size; i++) {
        for (j = 0; j < 3; j++) {
            printf("\t%d", g1[i].prices[j][0] * g1[i].playtime[j][0]);
        }
        printf("\n");
    }
}

int main() {
    int i, j,k,choice,r,c,size=0,num;
    int value,index=0;
    struct Games g1[10];

do{

printf("\nMenu :\n1).Adding a game. \n2).Displaying the price entered as matrix \n3).Displaying the price entered as matrix. \n4).For deleting a value from the price matrix. \n5).For deleting a value from the playtime matrix. \n6).For searching a value for the price matrix. \n7).For searching a value for the playtime matrix. \n8).For adding the price and playtime matrix. \n9).For multiplying the price and playtime matrix. \n10).Exit the program");
printf("\nEnter the choice : ");
scanf("%d",&choice);
switch(choice)
	{
		//For entering a new value
		case 1:
			printf("Enter the number of games you want to enter : ");
			scanf("%d",&num);
			if(size<10){
			
			for ( i = size; i < size + num && i < 10 ; i++) 
			{	get(&g1[i]);	}
			
			size += (num <= (10 - size)) ? num : (10 - size);
			}
			else{
				printf("Limit reached Can't add more games");
			}
		    break;
    
		// For displaying the price matrix	
		case 2:	
			printf("The prices : \n");
	        for(i=0;i<size;i++){
	        	priceDisplay(&g1[i]);
	        	printf("\n");
			}
			break;
		
		//For displaying the playtime matrix
		case 3:
			printf("\nThe playtime : \n");
	       	for(i=0;i<size;i++){
	        	ptDisplay(&g1[i]);
	        	printf("\n");
			}
			break;
		
		//For deleting an element from the price matrix
		case 4:
			printf("For deleting an element from the PRICES matrix");
			printf("Enter the game index (0 to %d): ", size - 1);
			scanf("%d",&r);
			printf("Enter the column index (0 for PS, 1 for PC, 2 for Mobile): ");
			scanf("%d",&c);
			delPrice(&g1, r, c, size);
			break;

		//For deleting an element from the playtime matrix
		case 5:
			printf("For deleting an element from the PLAYTIME matrix");
			printf("Enter the game index (0 to %d): ", size - 1);
			scanf("%d",&r);
			printf("Enter the column index (0 for PS, 1 for PC, 2 for Mobile): ");
			scanf("%d",&c);
			delPlay(&g1, r, c, size);
			break;
			
		//for linear search in prices
		case 6:
			printf("Enter the values you want to search in the PRICE matrix: ");
			scanf("%d",&value);
			linearSearchPrice(g1, value, size);
			break;
		
		//For linear seach in playtime
		case 7:
			printf("Enter the values you want to search in the PLAYTIME matrix: ");
			scanf("%d",&value);
			linearSearchPlay(g1, value, size);
			break;

		//addition 
		case 8:
			printf("Matrix obatined when adding PRICE and PLAYTIME matrices : \n");
			addMatrices(g1, size);
            break;
            
        //multiplication    
        case 9:
        	printf("Matrix obtained when multipling PRICE and PLAYTIME matices : \n");
        	multiplyMatrices(g1,size);
        	break;
        	
		case 10:
			printf("Exiting the program.\n");
            break;
		default:
                printf("Invalid choice. Please try again.\n");
		
	}
}while (choice != 10);
    return 0;
}

