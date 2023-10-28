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
void oddnDisplay(int n , int *arr)
{
	int i;
	printf("The odd numbers are : ");
	for(i=0;i<n;i++)
	{
		if(arr[i]%2==0)
		{
			printf("%d",arr[i]);
		}
		printf("\t");

	}
}
int main()
{
	int n;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	int arr[n];
	read(n,&arr);
	oddnDisplay(n,&arr);
	return 0;
}
