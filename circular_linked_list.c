#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

// Create a circular linked list
void create(int n) {
    struct Node *newNode, *temp;
    int data, i;

    for (i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &data);

        newNode->data = data;

        if (last == NULL) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }
}

// Insert at beginning
void insertBeginning(int data) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

// Insert at end
void insertEnd(int data) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

// Delete from beginning
void deleteBeginning() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (last->next == last) {
        free(last);
        last = NULL;
    } else {
        temp = last->next;
        last->next = temp->next;
        free(temp);
    }
}

// Delete from end
void deleteEnd() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (last->next == last) {
        free(last);
        last = NULL;
    } else {
        temp = last->next;

        while (temp->next != last) {
            temp = temp->next;
        }

        temp->next = last->next;
        free(last);
        last = temp;
    }
}

// Display circular linked list
void display() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;  // First node

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to first node)\n");
}

int main() {
    int n, choice, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    create(n);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Display\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}
