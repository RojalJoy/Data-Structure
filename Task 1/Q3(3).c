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
	printf("\nWhen the string is reversed : ");
	for(i=num;i--;)
	{
		printf("%c",str[i]);
	}
}
int main()
{
	char str[100];
	read(str);
	show(str);
	count(str);
	return 0;
}
