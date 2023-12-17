#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define size 10
int n=-1;
int array[size];

void insert_into_front(int val){
    if (n==size){
        printf("array is full\n");
        return;
    }
    for (int i=n;i>=0;i--){
        array[i+1]=array[i];
    }
    array[0]=val;
    n++;
}
void insert_into_back(int val){
    if (n==size){
        printf("array is full\n");
        return;
    }
    n++;
    array[n]=val;
}
void delete_at_back(){
    if (n==-1){
        printf("stack is empty\n");
        return;
    }
    printf("%d\n",array[n]);
    array[n]=0;
    n--;
}
void delete_at_front(){
    if (n==-1){
        printf("stack is empty\n");
        return;
    }
    printf("%d\n",array[n]);
    for (int i=0;i<=n;i++){
        array[i]=array[i+1];
    }
    array[n]=0;
    n--;
}

void isempty(){
    if (n==-1){
        printf("stack is empty\n");
    }
    else{
        printf("stack is not empty\n");
    }
}

void isfull(){
    if (n==size-1){
        printf("stack is full\n");
    }
    else{
        printf("stack is not full\n");
    }
}

void display()
{
    for (int i=0;i<=n;i++)
    {  
        printf("%d\t",array[i]);
    }
    printf("\n");
}

int main(){
    int option,value;
    while(1){
        printf("1.ins front\n");
        printf("2.ins back\n");
        printf("3.del front\n");
        printf("4.del back\n");
        printf("5.isfull\n");
        printf("6.isempty\n");
        printf("7.Exit\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("enter the value to front : ");
                scanf("%d",&value);
                insert_into_front(value);
                break;
            case 2:
                printf("enter the value to back : ");
                scanf("%d",&value);
                insert_into_back(value);
                break;
            case 3:
                delete_at_front();
                break;
            case 4:
                delete_at_back();
                break;
            case 5:
                display();
                break;
            case 6:
                isfull();
                break;
            case 7:
                isempty();
                break;
            case 8:
                exit(0);
        }
    }
}