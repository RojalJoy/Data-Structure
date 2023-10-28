#include<stdio.h>
#include<conio.h>

void read(int n ,int *arr)
{
	int i;
	printf("Enter the numbers : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
}
void display(int n , int *arr)
{
	int i;
	printf("The entered numbers are :");
	for(i=0;i<n;i++)
	{
		printf("\n%d",arr[i]);
	}
}
int main()
{
	int n;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	int arr[n];
	read(n,&arr);
	display(n,&arr);
	return 0;
	
	
}
