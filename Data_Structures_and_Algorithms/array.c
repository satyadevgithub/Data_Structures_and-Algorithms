#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"dsa.h"

// Function declarations

int* insert(int* size); // Function to insert an array
void display(int* array, int size); // Function to display the array
int* insertSortedAndUniqueData(int* size); // Function to insert sorted and unique data
int linearSearch(int *array, int size, int element, int index); // Linear search function
int binarySearch(int *array, int start, int end, int element); // Binary search function
void selectionSort(int *array, int size); // Selection sort function
void bubbleSort(int *array, int size); // Bubble sort function
void insertionSort(int *array, int size); // Insertion sort function
void heapSort(int *array, int size); // Heap sort function
void heapify(int *array, int size, int index); // Function to heapify a subtree
void mergeSort(int *array, int left, int right); // Merge sort function
void merge(int *array, int left, int mid, int right); // Function to merge two halves
void quickSort(int *array, int left, int right); // Quick sort function

int array() {
    printf("\n####### Welcome in Array Program #######\n");
    int choice, size = 0; // User's choice and size of the array
    int* array = NULL; // Pointer for the array

    while (1) { // Infinite loop for the menu
        printf("\n*****Menu*****\n");
        printf("1. Insert Sorted and Unique Data\n");
        printf("2. Linear Search\n");
        printf("3. Binary Search\n");
        printf("4. Selection Sort\n");
        printf("5. Bubble Sort\n");
        printf("6. Insertion Sort\n");
        printf("7. Heap Sort\n");
        printf("8. Merge Sort\n");
        printf("9. Quick Sort\n");
        printf("10. Exit\n");
        printf("Your Choice-> ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) { // Switch case for user choices
            case 1:
                array = insertSortedAndUniqueData(&size); // Insert sorted and unique data
                free(array); // Free allocated memory
                break;
            case 2: {
                int element; // Element to search for
                array = insertSortedAndUniqueData(&size); // Insert data for searching
                printf("Enter element to search: ");
                scanf("%d", &element); // User input for search element
                int index = linearSearch(array, size, element, 0); // Perform linear search
                if (index != -1) {
                    printf("Element %d found at index %d.\n", element, index);
                } else {
                    printf("Element %d not found in the array.\n", element);
                }
                free(array); // Free allocated memory
                break;
            }
            case 3: {
                int element; // Element to search for
                array = insertSortedAndUniqueData(&size); // Insert data for searching
                printf("Enter element to search: ");
                scanf("%d", &element); // User input for search element
                int index = binarySearch(array, 0, size - 1, element); // Perform binary search
                if (index != -1) {
                    printf("Element %d found at index %d.\n", element, index);
                } else {
                    printf("Element %d not found in the array.\n", element);
                }
                free(array); // Free allocated memory
                break;
            }
            case 4:
                array = insert(&size); // Insert data for selection sort
                selectionSort(array, size); // Perform selection sort
                free(array); // Free allocated memory
                break;
            case 5:
                array = insert(&size); // Insert data for bubble sort
                bubbleSort(array, size); // Perform bubble sort
                free(array); // Free allocated memory
                break;
            case 6:
                array = insert(&size); // Insert data for insertion sort
                insertionSort(array, size); // Perform insertion sort
                free(array); // Free allocated memory
                break;
            case 7:
                array = insert(&size); // Insert data for heap sort
                heapSort(array, size); // Perform heap sort
                free(array); // Free allocated memory
                break;
            case 8:
                array = insert(&size); // Insert data for merge sort
                mergeSort(array, 0, size - 1); // Perform merge sort
                printf("Merge Sorted Array-> ");
                display(array, size); // Display the sorted array
                free(array); // Free allocated memory
                break;
            case 9:
                array = insert(&size); // Insert data for quick sort
                quickSort(array, 0, size - 1); // Perform quick sort
                printf("Quick Sorted Array-> ");
                display(array, size); // Display the sorted array
                free(array); // Free allocated memory
                break;
            case 10:
                return main();
                //exit(0); // Exit the program
            default:
                printf("Invalid choice! Please try again.\n"); // Handle invalid choices
        }
    }
    return 0; // End of main function
}

// Function to insert an array based on user input
int* insert(int *size) {
    printf("Size of Array-> ");
    scanf("%d", size); // Read the size of the array
    int *array = (int*)malloc(*size * sizeof(int)); // Allocate memory for the array
    for (int i = 0; i < *size; i++) {
        printf("Index %d -> ", i);
        scanf("%d", &array[i]); // Read elements into the array
    }
    printf("Array-> ");
    display(array, *size); // Display the array
    return array; // Return the allocated array
}

// Function to display the array
void display(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("|%d ", array[i]); // Print each element
    }
    printf("|\n"); // End of array display
}

// Function to insert sorted and unique data into the array
int* insertSortedAndUniqueData(int* size) {
    printf("Size of Array-> ");
    scanf("%d", size); // Read the size of the array
    int *array = (int*)malloc(*size * sizeof(int)); // Allocate memory for the array
    int ele; // Variable to store the current element
    for (int i = 0; i < *size;) { // Loop until the array is filled
        printf("Element %d -> ", i + 1);
        scanf("%d", &ele); // Read the element

        // Check for duplicates
        int isDuplicate = 0; // Flag for duplicates
        for (int j = 0; j < i; j++) {
            if (array[j] == ele) { // Compare with existing elements
                isDuplicate = 1; // Set flag if duplicate found
                break;
            }
        }

        // If duplicate, prompt again
        if (isDuplicate) {
            printf("%d is already present in the array. Try again.\n", ele);
            continue; // Do not increment i, prompt again for the same index
        }

        // Insert element in sorted order
        int j;
        for (j = i; (j > 0) && (array[j - 1] > ele); j--) {
            array[j] = array[j - 1]; // Shift elements to make space
        }
        array[j] = ele; // Insert the new element
        i++; // Move to the next position
    }
    printf("Array-> ");
    display(array, *size); // Display the final array
    return array; // Return the allocated array
}

// Linear search implementation
int linearSearch(int *array, int size, int element, int index) {
    if (index >= size) return -1; // Base case: not found
    if (array[index] == element) return index; // Found the element
    return linearSearch(array, size, element, index + 1); // Search in the next index
}

// Binary search implementation
int binarySearch(int *array, int start, int end, int element) {
    while (start <= end) {
        int mid = start + (end - start) / 2; // Calculate mid index
        if (array[mid] == element) return mid; // Found the element
        if (element < array[mid]) return binarySearch(array, start, mid - 1, element); // Search left half
        if (element > array[mid]) return binarySearch(array, mid + 1, end, element); // Search right half
    }
    return -1; // Not found
}

// Selection sort implementation
void selectionSort(int *array, int size) {
    int i, j, min, temp; // Variables for sorting
    for (i = 0; i < size - 1; i++) {
        min = i; // Assume the minimum is the first element
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min]) {
                min = j; // Update min if a smaller element is found
            }
        }
        if (min != i) {
            // Swap the found minimum element with the first element
            temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
    printf("Selection Sorted Array-> ");
    display(array, size); // Display the sorted array
}

// Bubble sort implementation
void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) { // Loop through the array
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) { // Swap if the current element is greater than the next
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("Bubble Sorted Array-> ");
    display(array, size); // Display the sorted array
}

// Insertion sort implementation
void insertionSort(int *array, int size) {
    int i, key, j; // Variables for sorting
    for (i = 1; i < size; i++) { // Start from the second element
        key = array[i]; // Store the current element
        j = i - 1; // Index of the previous element
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j]; // Shift elements to make space
            j -= 1; // Move to the previous element
        }
        array[j + 1] = key; // Insert the key in the correct position
    }
    printf("Insertion Sorted Array-> ");
    display(array, size); // Display the sorted array
}

// Heap sort implementation
void heapSort(int *array, int size) {
    // Build heap
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(array, size, i); // Heapify each node
    }
    // Extract elements from heap
    for (int i = size - 1; i >= 0; i--) {
        int temp = array[0]; // Store the root (max element)
        array[0] = array[i]; // Move current root to end
        array[i] = temp; // Swap
        heapify(array, i, 0); // Heapify the reduced heap
    }
    printf("Heap Sorted Array-> ");
    display(array, size); // Display the sorted array
}

// Function to heapify a subtree
void heapify(int *array, int size, int index) {
    int largest = index; // Initialize largest as root
    int left = 2 * index + 1; // Left child
    int right = 2 * index + 2; // Right child
    if (left < size && array[left] > array[largest]) {
        largest = left; // Update largest if left child is greater
    }
    if (right < size && array[right] > array[largest]) {
        largest = right; // Update largest if right child is greater
    }
    if (largest != index) {
        // Swap and continue heapifying if root is not largest
        int temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;
        heapify(array, size, largest); // Recursively heapify the affected subtree
    }
}

// Merge sort implementation
void mergeSort(int *array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the mid point
        mergeSort(array, left, mid); // Sort the left half
        mergeSort(array, mid + 1, right); // Sort the right half
        merge(array, left, mid, right); // Merge the sorted halves
    }
}

// Function to merge two halves of an array
void merge(int *array, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid; // Size of right subarray

    int *L = (int*)malloc(n1 * sizeof(int)); // Left subarray
    int *R = (int*)malloc(n2 * sizeof(int)); // Right subarray

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }

    // Merge the temporary arrays back into array[left..right]
    i = 0; 
    j = 0; 
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k++] = L[i++]; // Copy from left subarray
        } else {
            array[k++] = R[j++]; // Copy from right subarray
        }
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        array[k++] = L[i++];
    }
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        array[k++] = R[j++];
    }

    free(L); // Free allocated memory for left subarray
    free(R); // Free allocated memory for right subarray
}

// Quick sort implementation
void quickSort(int *array, int left, int right) {
    if (left < right) {
        int pivot = array[right]; // Choose the rightmost element as pivot
        int i = left - 1; // Index of smaller element
        for (int j = left; j < right; j++) {
            if (array[j] < pivot) { // If current element is smaller than pivot
                i++; // Increment index of smaller element
                int temp = array[i]; // Swap
                array[i] = array[j];
                array[j] = temp;
            }
        }
        int temp = array[i + 1]; // Swap pivot to the correct position
        array[i + 1] = array[right];
        array[right] = temp;

        int pi = i + 1; // New pivot index
        quickSort(array, left, pi - 1); // Recursively sort elements before pivot
        quickSort(array, pi + 1, right); // Recursively sort elements after pivot
    }
}

