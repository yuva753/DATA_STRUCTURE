#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char Hint[100];//
    struct Node *next;
};
//head pointer null
struct Node* head=NULL;
struct Node* createNode(char Hint[]){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->Hint, Hint);
    newNode->next=NULL;
    return newNode;
}
void addSong(char Hint[]){
    struct Node* newNode=createNode(Hint);
    newNode->next=head;
    head=newNode;
    printf("Got my Hint: %s\n\n",Hint);
}
void display(){
    if(head==NULL)
    {
        printf("\n No Hint Here...\n");return;}
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%s ->",temp->Hint);
        temp=temp->next;
    }printf("NULL\n");
}
int main(){
    int choice;
    char HintName[100];
    while(1){printf("Choice 1: Bring Hint \nChoice 2: Display Hint\nChoice 3: Exit\nEnter your choice: ");
    scanf("%d",&choice);
    getchar();
    switch(choice){
        case 1:
            printf("Enter Your Hint:\n");
            fgets(HintName, sizeof(HintName), stdin);
            HintName[strcspn(HintName, "\n")] = 0;
            addSong(HintName);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Exiting From Treasure Hunt");
            exit(0);
        default:
            printf("Enter valid choice");
    }
    }
}
