//WAP to create a queue and perform enqueue and dequeue operation.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5


int arr[MAX];
int front = -1;
int rear = -1;

int isFull() {
    if (rear == MAX - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if (front == -1 || front > rear) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue overflow! Cannot enqueue %d\n", value);
    } else {
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow! Cannot dequeue\n");
        return -1;
    } else {
        int value = arr[front++];
        printf("%d dequeued from queue\n", value);
        return value;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}



//Theory


/*
1. Queue Data Structure:
   A queue is a linear data structure that follows the First In First Out (FIFO) principle.
   The first element added to the queue is the first one to be removed.
   
2. Operations on Queue:
   a. Enqueue: Adds an element to the rear (end) of the queue.
   b. Dequeue: Removes the element from the front of the queue.
   c. Display: Displays all elements currently in the queue.
   
3. The queue is implemented using arrays.
   The `front` variable is used to track the front element of the queue, and the `rear` variable is used to track the last element.
   If `front == -1` and `rear == -1`, the queue is empty.
   If `rear == MAX - 1`, the queue is full.

4. Functions in the Program:
   - isFull: Checks if the queue is full.
   - isEmpty: Checks if the queue is empty.
   - enqueue: Adds an element to the rear of the queue.
   - dequeue: Removes the front element from the queue.
   - display: Displays the current elements of the queue.
   
5. Time Complexity:
   - Enqueue and Dequeue operations: O(1), as they involve modifying the `front` and `rear` indices.
   - Display operation: O(n), where n is the number of elements in the queue.
   
6. Algorithm:
   a. **Enqueue Operation**:
      1. Check if the queue is full using `isFull()`.
      2. If full, print "Queue overflow".
      3. If not full, increment `rear` and add the element to the queue.
      4. Print the element enqueued.
   
   b. **Dequeue Operation**:
      1. Check if the queue is empty using `isEmpty()`.
      2. If empty, print "Queue underflow".
      3. If not empty, retrieve the element at the front and increment `front`.
      4. Print the element dequeued.

   c. **Display Operation**:
      1. Check if the queue is empty using `isEmpty()`.
      2. If empty, print "Queue is empty".
      3. If not empty, print all elements from the `front` to `rear`.
*/