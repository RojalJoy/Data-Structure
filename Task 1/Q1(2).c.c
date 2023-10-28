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
void oddpDisplay(int n , int *arr)
{
	int i;
	printf("The odd positioned numbers are : ");
	for(i=1;i<n;i+=2)
	{
		printf("%d\t",arr[i]);
	}
}
int main()
{
	int n;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	int arr[n];
	read(n,&arr);
	oddpDisplay(n,&arr);
	return 0;
}
