// Aim : WAP to perform linear and binary search .

#include <stdio.h>

void linearSearch(int arr[], int n, int key) {
    int i;
    int flag = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d using Linear Search.\n", key, i + 1);
            flag = 1;
            break;
        }
    }

    if (!flag) {
        printf("Element %d not found using Linear Search.\n", key);
    }
}

void binarySearch(int arr[], int n, int key) {
    int left, right, mid;
    int flag = 0;

    left = 0;
    right = n - 1;

    while (left <= right) {
        mid = (left + right ) / 2;

        if (arr[mid] == key) {
            printf("Element %d found at position %d using Binary Search.\n", key, mid + 1);
            flag = 1;
            break;
        }

        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!flag) {
        printf("Element %d not found using Binary Search.\n", key);
    }
}

int main() {
    int n;
    int i, key;
    int arr[100];

    printf("Enter the size of an array: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order for Binary Search:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    linearSearch(arr, n, key);
    binarySearch(arr, n, key);

    return 0;
}


/*
Linear Search:
- A simple search algorithm that checks each element in the array one by one.
- Time Complexity: O(n) in the worst case, as it may need to check all elements.
- Works on unsorted or sorted arrays.
- Suitable for small datasets or unsorted data.
- Example: Searching for a specific number in an array of size n.
*/

/*
Binary Search:
- An efficient search algorithm that works on sorted arrays.
- Divides the search interval in half repeatedly to find the target element.
- Time Complexity: O(log n) in the worst case.
- Requires the array to be sorted before performing the search.
- Suitable for large datasets with sorted data.
- Example: Searching for a number in a sorted array of size n by repeatedly halving the search space.
*/