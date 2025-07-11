#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct directory {
    char *filename;
    struct directory *next;
    struct directory *prev;
};

struct directory *head = NULL;
struct directory *tail = NULL;
struct directory *curr = NULL;

void insertdirectory(char *filename) {
    struct directory *newdirectory = (struct directory*)malloc(sizeof(struct directory));
    newdirectory->filename = (char*)malloc(strlen(filename) + 1);
    strcpy(newdirectory->filename, filename);

    if (head == NULL) {
        head = tail = newdirectory;
        newdirectory->next = newdirectory->prev = NULL;
    } else {
        newdirectory->prev = NULL;
        newdirectory->next = head;
        head->prev = newdirectory;
        head = newdirectory;
    }
    curr = head;  
}

int prevdirectory() {
    if (curr->next != NULL) {
        curr = curr->next;
        return 1;
    }
    return 0;
}

int nextdirectory() {
    if (curr->prev != NULL) {
        curr = curr->prev;
        return 1;
    }
    return 0;
}

void traversal() {
    char key;
    printf("\nTraversal started.\n");
    printf("P = previous directory, N = next directory, E = exit\n");
    printf("Current: %s\n", curr->filename);

    while (1) {
        printf("\nEnter choice: ");
        scanf(" %c", &key);

        if (key == 'E') {
            printf("Exiting traversal.\n");
            break;
        }

        if (key == 'P' && prevdirectory()) {
            printf("Previous: %s\n", curr->filename);
        } 
        else if (key == 'N' && nextdirectory()) {
            printf("Next: %s\n", curr->filename);
        } 
        else {
            printf("At boundary: %s\n", curr->filename);
        }
    }
}

int main() {
    int n;
    char temp[100];

    printf("How many directories do you want to add? ");
    scanf("%d", &n);
    getchar(); 

    for (int i = 0; i < n; i++) {
        printf("Enter directory %d name: ", i + 1);
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = 0; 
        insertdirectory(temp);
    }

    traversal();
    return 0;
}
