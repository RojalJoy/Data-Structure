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
int main()
{
	char str[100];
	read(str);
	show(str);
	return 0;
}
