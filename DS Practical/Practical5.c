//AIM : WAP to perform following operations on a singly linked list:
//1. Insert at the beginning
//2. Insert at the end
//3. Insert at a specific position
//4. Delete from the beginning
//5. Delete from the end
//6. Delete from a specific position
//7. Display the linked list
//8. Exit


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;


void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtPosition(int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is out of range\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    if (position == 1) {
        head = head->next;
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position is out of range\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\n1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from a specific position\n");
        printf("7. Display the linked list\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &value, &position);
                insertAtPosition(value, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

//Theory

/*
   Brief Theory of Singly Linked List Operations

   A Singly Linked List is a data structure consisting of nodes, 
   where each node contains two parts:
   - Data: Holds the actual value.
   - Next: A pointer to the next node in the list (or NULL if it's the last node).

   The list is called "singly" because each node points to the next node, but not the previous one.

   Operations on Singly Linked List:

   1. Insert at the Beginning:
      - Add a new node at the start of the list.
      - The new node's 'next' pointer points to the current head, and the head is updated to the new node.

   2. Insert at the End:
      - Add a new node at the end of the list.
      - Traverse the list to the last node and set its 'next' pointer to the new node.

   3. Insert at a Specific Position:
      - Add a new node at a given position.
      - Traverse the list to the desired position and adjust pointers to insert the new node at the specified location.

   4. Delete from the Beginning:
      - Remove the first node from the list.
      - Update the head pointer to the second node, and free the memory of the old head.

   5. Delete from the End:
      - Remove the last node from the list.
      - Traverse the list to the second-last node, set its 'next' pointer to NULL, and free the memory of the last node.

   6. Delete from a Specific Position:
      - Remove a node from a given position.
      - Traverse to the node before the target position, adjust the pointers to skip the node to be deleted, and free its memory.

   7. Display the Linked List:
      - Traverse the entire list and print the data of each node.

   Time Complexity of Operations:
   - Insert at the beginning: O(1)
   - Insert at the end: O(n), where n is the number of nodes (due to traversal).
   - Insert at a specific position: O(n), where n is the number of nodes (due to traversal).
   - Delete from the beginning: O(1)
   - Delete from the end: O(n), where n is the number of nodes (due to traversal).
   - Delete from a specific position: O(n), where n is the number of nodes (due to traversal).
   - Display: O(n), where n is the number of nodes (due to traversal).

   Use Cases:
   - Dynamic memory allocation: Linked lists do not require contiguous memory, allowing dynamic memory allocation.
   - Efficient insertions and deletions: Especially useful when frequent insertions or deletions are needed.
*/
