//AIM : WAP to perform stack PUSH AND POP operation using array.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

int isFull() {
    if (top == MAX - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(int value) {
    if (isFull()) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    } else {
        int value = stack[top--];
        printf("%d popped from stack\n", value);
        return value;
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        } else if (choice == 2) {
            pop();
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

//Theory : 

/*
1. Stack Data Structure:
   A stack is a linear data structure that follows the Last In First Out (LIFO) principle.
   The last element added to the stack is the first one to be removed.
   
2. Operations on Stack:
   a. Push: Adds an element to the top of the stack.
   b. Pop: Removes the element from the top of the stack.
   c. Display: Displays all elements currently in the stack.
   
3. The stack is implemented using an array.
   The `top` variable is used to track the top element of the stack.
   If `top == -1`, the stack is empty.
   If `top == MAX - 1`, the stack is full.

4. Functions in the Program:
   - isFull: Checks if the stack is full.
   - isEmpty: Checks if the stack is empty.
   - push: Adds an element to the top of the stack.
   - pop: Removes the top element from the stack.
   - display: Displays the current elements of the stack.
   
5. Time Complexity:
   - Push and Pop operations: O(1), as they involve modifying the `top` index.
   - Display operation: O(n), where n is the number of elements in the stack.
   
6. Algorithm:
   a. **Push Operation**:
      1. Check if the stack is full using `isFull()`.
      2. If full, print "Stack overflow".
      3. If not full, increment `top` and add the element to the stack.
      4. Print the element pushed.
   
   b. **Pop Operation**:
      1. Check if the stack is empty using `isEmpty()`.
      2. If empty, print "Stack underflow".
      3. If not empty, retrieve and remove the element at the top, then decrement `top`.
      4. Print the element popped.

   c. **Display Operation**:
      1. Check if the stack is empty using `isEmpty()`.
      2. If empty, print "Stack is empty".
      3. If not empty, print all elements from `top` to the bottom.
*/