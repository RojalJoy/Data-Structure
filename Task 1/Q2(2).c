#include<stdio.h>
#include<conio.h>

int main()
{
	int n,i,j;
	printf("Enter the no.of columns  of the square matrix : ");
	scanf("%d",&n);
	
	int arr[n][n];
	printf("Enter the elements of the array:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int sum;
	printf("The rowwise sum of the elements : ");
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<n;j++)
		{
			sum+=arr[i][j];
		}
		printf("The sum of the elements of row %d is : %d \n",i+i,sum);
		
	}
	return 0;
}
