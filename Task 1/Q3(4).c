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

void copy(char *str)
{
	char str2[100];
	int num=0,i;
	while(str[num]!='\0')
	{
		num++;
	}
	for(i=0;i<num;i++)
	{
		str2[i]=str[i];
	}
	printf("\nThe copied string is : %s",str2);
}
int main()
{
	char str[100];
	read(str);
	show(str);
	copy(str);
	return 0;
}
