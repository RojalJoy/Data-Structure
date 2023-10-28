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
void sum(int n,int *arr)
{
	int i,value=0;
	for (i=0;i<n;i++)
	{
		value+=arr[i];
	}
	printf("The sum of the elements in the given array is : %d",value);
}
void avg(int n ,int *arr)
{
	int i,value=0;
	float res;
	for (i=0;i<n;i++)
	{
		value+=arr[i];
	}
	res=value/n;
	printf("\nThe average of the elements in the given array is : %f",res);
}
int main()
{
	int n;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	int arr[n];
	read(n,&arr);
	sum(n,&arr);
	avg(n,&arr);
	return 0;
}
