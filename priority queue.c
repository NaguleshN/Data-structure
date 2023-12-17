#include<stdio.h>
#include<stdlib.h>

#define max_size 10
struct node{
    int priority;
    int value;
};

struct node pqueue[max_size],temp;
int front=-1,rear=-1;

void enqueue(){
    if (rear==max_size-1){
        printf("full");
    }
    else if(front==-1&&rear==-1){
        front++;rear++;
        scanf("%d",&pqueue[front].priority);
        scanf("%d",&pqueue[front].value);
    }
    else{
        int i=rear;
        scanf("%d",&temp.priority);
        scanf("%d",&temp.value);
        while(pqueue[i].priority>temp.priority){
            pqueue[i+1].priority=pqueue[i].priority;
            pqueue[i+1].value=pqueue[i].value;
            i--;
        }
        pqueue[i+1].priority=temp.priority;
        pqueue[i+1].value=temp.value;
        rear++;
    }
    
}

void dequeue(){
    if (front==-1&&rear==-1){
        printf("empty"
        );

    }
    else if (front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }

}

void display(){
    if(front!=-1){

    for(int j=front;j<=rear;j++){
        printf("\n");
        printf("%d\t",pqueue[j].priority);
        printf("%d",pqueue[j].value);
    }
    }
    else{
        printf("no elements");
    }
}


int main()
{
    int option;
    while(1){
    scanf("%d",&option);
    switch(option){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);


    }
    }

}