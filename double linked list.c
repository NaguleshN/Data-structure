#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};
struct node *head,*temp,*curr;

void insert_front(){
    if (head==NULL)
    {
        head=(struct node *)malloc(sizeof(struct node));
        printf("enter the data :");
        scanf("%d",&head->data);printf("%d",head->data);
        head->left=NULL;
        head->right=NULL;
    }
    else{
        temp=(struct node *)malloc(sizeof(struct node));
        printf("enter the data :");
        scanf("%d",&temp->data);
        temp->left=NULL;
        temp->right=head;
        head->left=temp;
        head=temp;
    }
}

void insert_back(){
    curr=head;
    while(curr->right!=NULL){
        // printf("%d",temp->data);
        curr=curr->right;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter the data :");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    curr->right=temp;
    temp->left=curr;

}

void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        printf("\n");
        temp=temp->right;
    }
}

int main(){

    int option;
    while(1){
        printf("choose your option :");
        printf("1.insert at front");
        printf("4.display");
        scanf("%d",&option);
        switch(option){
            case 1:
                insert_front();
                break;
            case 2:
                insert_back();
                break;
            case 3:
                exit(0);
            case 4:
                display();
                break;
            default:
                printf("invalid");
        }
    }

}