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
	printf("The entered elements are:");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t",arr[i][j]);
		}
	}
	return 0;
}
