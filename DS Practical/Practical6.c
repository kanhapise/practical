//WAP to perform following operations on a doubly linked list:
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
    struct Node* prev;
};

struct Node* head = NULL;

void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    
    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) {
            head->prev = newNode;
        }
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
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }

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
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is out of range\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
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




//Theory:
/*
   Theory of Doubly Linked List Operations:

   A Doubly Linked List is a data structure where each node contains three parts:
   - Data: Stores the actual value.
   - Next: Points to the next node in the list.
   - Prev: Points to the previous node in the list.

   The key feature of a doubly linked list is that it allows traversal in both directions:
   - Forward direction (using the next pointer).
   - Backward direction (using the previous pointer).

   Operations on Doubly Linked List:

   1. Insert at the Beginning:
      - A new node is created and inserted at the head of the list.
      - The new node's next pointer points to the current head, and the prev pointer is set to NULL.
      - If the list is not empty, the current head's prev pointer is updated to the new node.
   
   2. Insert at the End:
      - A new node is created and added to the end of the list.
      - The list is traversed to find the last node, and the new node is inserted after it.
      - The new node's prev pointer points to the last node, and its next pointer is set to NULL.

   3. Insert at a Specific Position:
      - A new node is created and inserted at the specified position in the list.
      - The list is traversed to the position where the new node will be inserted.
      - The next and prev pointers of surrounding nodes are updated to link the new node.

   4. Delete from the Beginning:
      - The first node is deleted by updating the head pointer to the second node.
      - The second node's prev pointer is set to NULL, and the first node is freed from memory.

   5. Delete from the End:
      - The last node is deleted by traversing to the second-last node.
      - The second-last node's next pointer is set to NULL, and the last node is freed from memory.

   6. Delete from a Specific Position:
      - A node at the specified position is deleted by adjusting the next and prev pointers of surrounding nodes.
      - The node at the specified position is freed from memory.

   7. Display the Linked List:
      - The entire list is traversed, and the data of each node is printed.
      - The nodes are displayed in a forward direction, from the head to the tail of the list.

   Time Complexity of Operations:
   - Insert at the beginning: O(1)
   - Insert at the end: O(n), where n is the number of nodes (due to traversal).
   - Insert at a specific position: O(n), where n is the number of nodes (due to traversal).
   - Delete from the beginning: O(1)
   - Delete from the end: O(n), where n is the number of nodes (due to traversal).
   - Delete from a specific position: O(n), where n is the number of nodes (due to traversal).
   - Display: O(n), where n is the number of nodes (due to traversal).

   Use Cases:
   - Doubly linked lists are useful when bidirectional traversal is needed, allowing access from both ends of the list.
   - They provide more efficient insertion and deletion at both ends of the list compared to singly linked lists.
   - They are more memory-intensive due to the extra pointer for the previous node, but they provide more flexibility.
*/
