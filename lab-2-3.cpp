#include<stdio.h>
#define MAX_SIZE 100
void inputArray(int arr[], int *size);
void displayArray(int arr[], int size);
int searchValue(int arr[], int size, int target);
void calculateStatistics(int arr[], int size);
void reverseArray(int arr[], int size);

int main() {
    int arr[MAX_SIZE], size = 0, target, index, choice;

  
    do {
        printf("\n--- Menu ---\n");
        printf("1. Input data\n");
        printf("2. Display array\n");
        printf("3. Search for a number\n");
        printf("4. Calculate statistics (Sum, Average, Max, Min)\n");
        printf("5. Reversed array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                inputArray(arr, &size);
                break;

            case 2: 
                if (size > 0) {
                    displayArray(arr, size);
                } else {
                    printf("No data to display. Please input data first.\n");
                }
                break;

            case 3:
                if (size > 0) {
                    printf("Enter the number you want to search for: ");
                    scanf("%d", &target);
                    index = searchValue(arr, size, target);
                    if (index != -1) {
                        printf("The number %d is found at index %d.\n", target, index);
                    } else {
                        printf("The number %d is not found in the array.\n", target);
                    }
                } else {
                    printf("No data available to search. Please input data first.\n");
                }
                break;

            case 4:
                if (size > 0) {
                    calculateStatistics(arr, size);
                } else {
                    printf("No data available to calculate statistics. Please input data first.\n");
                }
                break;

            case 5:
                reverseArray(arr, size);
                break;

            case 6: 
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}


void inputArray(int arr[], int *size) {
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", size);
    if (*size <= MAX_SIZE && *size > 0) {
        printf("Enter %d elements:\n", *size);
        for (int i = 0; i < *size; i++) {
            printf("Number %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
        printf("Data input successful.\n");
    } else {
        printf("Size exceeds maximum limit of %d or is invalid.\n", MAX_SIZE);
        *size = 0;
    }
}

void displayArray(int arr[], int size) {
    if (size > 0) {
        printf("Array elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("No data to display. Please input data first.\n");
    }
}


int searchValue(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}


void calculateStatistics(int arr[], int size) {
    if (size > 0) {
        int sum = 0, max = arr[0], min = arr[0];
        for (int i = 0; i < size; i++) {
            sum += arr[i];
            if (arr[i] > max) max = arr[i];
            if (arr[i] < min) min = arr[i];
        }
        float average = (float)sum / size;
        printf("Statistics:\n");
        printf("Sum: %d\n", sum);
        printf("Average: %.2f\n", average);
        printf("Max: %d\n", max);
        printf("Min: %d\n", min);
    } else {
        printf("No data available to calculate statistics. Please input data first.\n");
    }
}

void reverseArray(int arr[], int size) {
    if (size > 0) {
        int reversed[MAX_SIZE];
        for (int i = 0; i < size; i++) {
            reversed[i] = arr[size - 1 - i];
        }
        printf("Reversed array: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", reversed[i]);
        }
        printf("\n");
    } else {
        printf("No data to reverse. Please input data first.\n");
    }
}