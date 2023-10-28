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
	
	int ident=1;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j&&arr[i][j]!=1)
			{
				ident=0;
				break;
			}
			if(i!=j&&arr[i][j]!=0)
			{
				ident=0;
				break;
			}
		}
	}
	
	if(ident)
	{
		printf("The entered matrix is an identity matrix");
	}
	else
	{
		printf("The entered matrix is not an identity matrix");
	}
	return 0;
}
