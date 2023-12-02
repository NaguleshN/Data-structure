#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define size 10
int top=-1;
int stack[size];

void push(int n){
    if (top==size-1){
        printf("stack is full\n");
        return;
    }
    top++;
    stack[top]=n;
}
void pop(){
    if (top==-1){
        printf("stack is empty\n");
        return;
    }
    printf("%d\n",stack[top]);
    stack[top]=0;
    top--;
}

void isempty(){
    if (top==-1){
        printf("stack is empty\n");
    }
    else{
        printf("stack is not empty\n");
    }
}

void isfull(){
    if (top==size-1){
        printf("stack is full\n");
    }
    else{
        printf("stack is not full\n");
    }
}
void peek()
{
    printf("%d\n",stack[top]);
}

void display()
{
    for (int i=0;i<=top;i++)
        printf("%d\t",stack[i]);
}

int main(){
    int option,value;
    while(1){
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.isfull\n");
        printf("6.isempty\n");
        printf("7.Exit\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("enter the value to push : ");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                isfull();
                break;
            case 6:
                isempty();
                break;
            case 7:
                exit(0);
        }

    }

}