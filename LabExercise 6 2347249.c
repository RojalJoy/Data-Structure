#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Game {
    int gameID;
    char title[50];
    float rating;
};

int comparisonCount = 0;
int dataTransferCount = 0;

void merge(struct Game arr[], int l, int m, int r);
void mergeSort(struct Game arr[], int l, int r);
int partition(struct Game arr[], int low, int high);
void quickSort(struct Game arr[], int low, int high);
void printGames(struct Game arr[], int size);
void generateRandomGames(struct Game arr[], int size);
void writeToFile(struct Game arr[], int size, const char *filename);
void readFromFile(struct Game arr[], int size, const char *filename);

int main() {
    srand(time(NULL));
    int size = 10;
    struct Game games[size];

    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Generate Random Games and Write to File\n");
        printf("2. Read Games from File\n");
        printf("3. Merge Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Print Games\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateRandomGames(games, size);
                writeToFile(games, size, "unsorted_games.txt");
                printf("Random games generated and written to file.\n");
                break;

            case 2:
                readFromFile(games, size, "unsorted_games.txt");
                printf("Games read from file.\n");
                break;

            case 3:
                comparisonCount = 0;
                dataTransferCount = 0;
                mergeSort(games, 0, size - 1);
                printf("After Merge Sort:\n");
                printGames(games, size);
                printf("Number of comparisons in Merge Sort: %d\n", comparisonCount);
                printf("Number of data transfer operations in Merge Sort: %d\n", dataTransferCount);
                break;

            case 4:
                comparisonCount = 0;
                dataTransferCount = 0;
                quickSort(games, 0, size - 1);
                printf("After Quick Sort:\n");
                printGames(games, size);
                printf("Number of comparisons in Quick Sort: %d\n", comparisonCount);
                printf("Number of data transfer operations in Quick Sort: %d\n", dataTransferCount);
                break;

            case 5:
                printf("Current Games:\n");
                printGames(games, size);
                break;

            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}




void merge(struct Game arr[], int l, int m, int r) {
      int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    struct Game L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        comparisonCount++;
        if (L[i].gameID <= R[j].gameID) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        dataTransferCount++;
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        dataTransferCount++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        dataTransferCount++;
    }

}

void mergeSort(struct Game arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

int partition(struct Game arr[], int low, int high) {
    struct Game pivot = arr[high];
    int i = (low - 1),j;

    for (j = low; j <= high - 1; j++) {
        comparisonCount++;
        if (arr[j].gameID <= pivot.gameID) {
            i++;

            // Swap arr[i] and arr[j]
            struct Game temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            dataTransferCount += 3; // Three data transfers for the swap
        }
    }

    // Swap arr[i+1] and arr[high] (pivot)
    struct Game temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    dataTransferCount += 3; // Three data transfers for the swap

    return i + 1;
}

void quickSort(struct Game arr[], int low, int high) {
     if (low < high) {
        // Find pivot element such that elements smaller than pivot are on the left
        // and elements greater than pivot are on the right
        int pi = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printGames(struct Game arr[], int size) {
    	int i;
    for ( i = 0; i < size; i++) {
        printf("Game ID: %d, Title: %s, Rating: %.2f\n", arr[i].gameID, arr[i].title, arr[i].rating);
    }
}

void generateRandomGames(struct Game arr[], int size) {
	int i;
    for ( i = 0; i < size; i++) {
        arr[i].gameID = rand() % 1000 + 1;
        sprintf(arr[i].title, "Game %d", arr[i].gameID);
        arr[i].rating = (float)(rand() % 50) / 10.0 + 1.0;
    }
}

void writeToFile(struct Game arr[], int size, const char *filename) {
	int i;
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        for ( i = 0; i < size; i++) {
            fprintf(file, "%d %s %.2f\n", arr[i].gameID, arr[i].title, arr[i].rating);
        }
        fclose(file);
    } else {
        printf("Error opening file for writing.\n");
    }
}

void readFromFile(struct Game arr[], int size, const char *filename) {
	int i;
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        for ( i = 0; i < size; i++) {
            fscanf(file, "%d %s %f", &arr[i].gameID, arr[i].title, &arr[i].rating);
        }
        fclose(file);
    } else {
        printf("Error opening file for reading.\n");
    }
}

