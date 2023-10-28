#include <stdio.h>
#include <stdlib.h>

void read(char **names, int n)
 {
 	int i;
    for (i = 0; i < n; i++) 
	{
        printf("Enter name %d: ", i + 1);
        names[i] = (char *)malloc(100 * sizeof(char)); 
        scanf("%s", names[i]);
    }
}

void show(char **names, int n)
 {
 	int i;
    printf("Entered names:\n");
    for ( i = 0; i < n; i++)
	{
        printf("Name %d: %s\n", i + 1, names[i]);
    }
}

int main()
{
    int n;

    printf("Enter the number of names: ");
    scanf("%d", &n);

    if (n <= 0) 
	{
        printf("Invalid input.\n");
        return 1;
    }

    char **names = (char **)malloc(n * sizeof(char *)); 


    read(names, n);
    show(names, n);

    return 0;
}

