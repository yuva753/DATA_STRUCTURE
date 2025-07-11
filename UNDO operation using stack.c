#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Stack Node
struct StackNode {
    char data[MAX_LEN];
    struct StackNode* next;
};

// Push operation
void push(struct StackNode** top, const char* action) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (!newNode) {
        printf("Stack overflow\n");
        return;
    }
    strcpy(newNode->data, action);
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
void pop(struct StackNode** top) {
    if (*top == NULL) {
        printf("Nothing to undo!\n");
        return;
    }
    struct StackNode* temp = *top;
    printf("Undo: %s\n", temp->data);
    *top = (*top)->next;
    free(temp);
}

// Display current stack
void displayStack(struct StackNode* top) {
    printf("Current Actions (top to bottom):\n");
    while (top != NULL) {
        printf("- %s\n", top->data);
        top = top->next;
    }
}

// Main
int main() {
    struct StackNode* actionStack = NULL;
    int choice;
    char action[MAX_LEN];

    while (1) {
        printf("\n1. Perform Action\n2. Undo Last Action\n3. Show Actions\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter action: ");
                fgets(action, MAX_LEN, stdin);
                action[strcspn(action, "\n")] = '\0'; // Remove newline
                push(&actionStack, action);
                break;
            case 2:
                pop(&actionStack);
                break;
            case 3:
                displayStack(actionStack);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
