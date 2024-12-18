// WAP to perform Sorting : Selection , Insertion  and bubble sort.


#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    printf("Array after Selection Sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Array after Insertion Sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array after Bubble Sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    int arr[100], originalArr[100];

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        originalArr[i] = arr[i];
    }

    selectionSort(arr, n);

    for (i = 0; i < n; i++) {
        arr[i] = originalArr[i];
    }

    insertionSort(arr, n);

    for (i = 0; i < n; i++) {
        arr[i] = originalArr[i];
    }

    bubbleSort(arr, n);

    return 0;
}


//Theory

 /* 
    1. Selection Sort:
    Concept: Selection Sort works by repeatedly finding the smallest element from the unsorted portion of the array and swapping it with the first unsorted element.
    Algorithm:
    - Start at the beginning of the array and find the smallest element in the unsorted portion.
    - Swap the smallest element with the first unsorted element.
    - Move the boundary of the unsorted portion one step to the right.
    - Repeat the process until the entire array is sorted.
    Time Complexity: O(n²) — two nested loops, making it inefficient for large datasets.
    Use: Simple but inefficient for large data sets.

    2. Insertion Sort:
    Concept: Insertion Sort builds the final sorted array one item at a time by repeatedly picking the next element and inserting it into the correct position in the sorted portion.
    Algorithm:
    - Start with the second element (index 1).
    - Compare it with the element before it (index 0). If it's smaller, shift the larger elements to the right.
    - Insert the current element at its correct position in the sorted part.
    - Repeat this for each subsequent element until the array is sorted.
    Time Complexity: O(n²) — worst-case scenario when the array is sorted in reverse order.
    Use: Efficient for small datasets or nearly sorted arrays.

    3. Bubble Sort:
    Concept: Bubble Sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the array is sorted.
    Algorithm:
    - Start at the beginning of the array.
    - Compare adjacent elements. If the current element is greater than the next, swap them.
    - Continue comparing and swapping adjacent elements until the largest element moves to its correct position at the end of the array.
    - Repeat the process for the remaining unsorted portion of the array.
    - Stop when no swaps are required, indicating the array is sorted.
    Time Complexity: O(n²) — inefficient for large datasets because it requires multiple passes over the array.
    Use: Simple to implement, but not suitable for large datasets due to its time complexity.
    */