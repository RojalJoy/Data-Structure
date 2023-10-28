#include<stdio.h>
#include<conio.h>

void read(char *str)
{
	printf("Enter a string : ");
	scanf("%s",str);
}

void show(char *str)
{
	printf("The entered string is : %s",str);
}

void count(char *str)
{
	int num=0,i;
	while(str[num]!='\0')
	{
		num++;
	}
	printf("\nThe lenght of the entered string is : %d",num);
}
int main()
{
	char str[100];
	read(str);
	show(str);
	count(str);
	return 0;
}
