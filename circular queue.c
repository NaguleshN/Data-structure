#include<stdio.h>
#include<stdlib.h>
#define max_size 10
int front=-1,rear=-1;
int queue[max_size];
void enqueue(int val){
    // if (rear==max_size-1){
    if(front==(rear+1)%max_size){
        printf("full");
    }
    else if(front==-1&&rear==-1){
        front++;rear++;
        queue[rear]=val;
    }
    else{
        rear=(rear+1)%max_size;
        queue[rear]=val;
    }

}


void dequeue(){
    if (front==-1&&rear==-1){
        printf("empty");

    }
    else if(front==rear){
        queue[front]=0;
        front=-1;
        rear=-1;
    }
        
    else{
        queue[front]=0;
        front=(front+1)%max_size;

    }
}


void display(){
    int i;
    for( i=front;i!=rear;i++){
        i=i%max_size;
        printf("%d",queue[i]);
    }printf("%d",queue[rear]);
}
int main(){
    int option,val;
while(1){

scanf("%d",&option);
switch(option){
    case 1:
        printf("enter the data: ");
        scanf("%d",&val);
        enqueue(val);
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