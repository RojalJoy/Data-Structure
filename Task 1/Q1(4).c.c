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
int max(int n , int *arr)
{
	int i,max=arr[0];
	for(i=0;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
}
int main()
{
	int n;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	int arr[n];
	read(n,&arr);
	int mnumber=max(n,&arr);
	printf("The maximum number in the entered array is : %d",mnumber);
	return 0;
}
