#include<stdio.h>
#include<conio.h>

void read(char *str)
{
	printf("Enter a string : ");
	scanf("%s",str);
}

void show(char *str)
{
	printf("\nThe entered string is : %s",str);
}

void find(char *str)
{
	int num=0,i,count=0;
	char word;
	
	printf("\nEnter a character to search : ");
	scanf(" %c",&word);
	
	while(str[num]!='\0')
	{
		num++;
	}
	

	for(i=0;i<num;i++)
	{
		if(word==str[i])
		{
			count++;
		}
	}
	printf("\nThe character occcured in the word %d times : ",count);
}
int main()
{
	char str[100];
	read(str);
	show(str);
	find(str);
	return 0;
}
