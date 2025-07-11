#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at end using head and tail double pointers
void insertEnd(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

// Make the doubly linked list circular using single pointers
void makeCircular(struct Node* head, struct Node* tail) {
    if (head == NULL || tail == NULL)
        return;

    tail->next = head;
    head->prev = tail;
}

// Solve Josephus Problem
int solveJosephus(struct Node** head, int k) {
    struct Node* current = *head;
    int count;

    while (current->next != current) {
        count = 1;
        while (count < k) {
            current = current->next;
            count++;
        }

        printf("Player %d is eliminated\n", current->data);

        // Remove current
        current->prev->next = current->next;
        current->next->prev = current->prev;

        // Update head if current is head
        if (current == *head)
            *head = current->next;

        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    printf("Player %d is the winner!\n", current->data);
    int winner = current->data;
    free(current);
    return winner;
}

// Main function
int main() {
    int n, k;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter number of players: ");
    scanf("%d", &n);

    printf("Enter value of k (eliminate every k-th player): ");
    scanf("%d", &k);

    // Insert players
    for (int i = 1; i <= n; i++) {
        insertEnd(&head, &tail, i);
    }

    // Make circular (single pointer version)
    makeCircular(head, tail);

    // Solve the game
    solveJosephus(&head, k);

    return 0;
}
