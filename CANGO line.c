#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char person[100];
    struct Node* next;
};

struct Node* head = NULL;

void addperson(char person[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->person, person);
    newNode->next = head;
    head = newNode;  // fix: update head to point to new node
}

void display() {
    if (head == NULL) {
        printf("No persons in the line...\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->person);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    char personName[100];

    while (1) {
        printf("\nChoice 1: Add a person\nChoice 2: Display persons\nChoice 3: Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume leftover newline

        switch (choice) {
            case 1:
                printf("Enter person name: ");
                fgets(personName, sizeof(personName), stdin);
                personName[strcspn(personName, "\n")] = 0; // remove newline
                addperson(personName);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Enter a valid choice.\n");
        }
    }

    return 0;
}
