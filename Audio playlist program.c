#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char song[100];
    struct Node *next;
    
};
//head pointer NULL
struct Node* head=NULL;
struct Node* createNode(char song[]){//Dandeliones
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->song, song);
    newNode->next=NULL;
    return newNode;
}
void addsong(char song[]){
    struct Node* newNode=createNode(song);
    newNode->next=head;
    head=newNode;
    printf("%s added to the playlist",song);
    
}
void display(){
    if(head==NULL)
    {
        printf("\n No songs to play...");return;}
        struct Node* temp=head;
        while(temp!=NULL){
            printf("%s->",temp->song);
            temp=temp->next;
        }printf("NULL");
    }
int main(){
    int choice;char songName[100];
    printf("choice 1: Add a song\nchoice 2: Display song\nchoice 3: Exit\nEnter your choice");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("\nEnter song name");
        fgets(songName, sizeof(songName),stdin);
        songName[strcspn(songName, "\n")] = 0;
        addsong(songName);
        break ;
        
        case 2 :
        display();
        break;
        case 3:
        printf("Exiting playlist");
        exit(0);
        default:
        printf("Enter the valid choice");
    }
    return 0;
}
