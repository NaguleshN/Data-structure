#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10
int stack[10];
int top;
//push
void push(int temp)
{
    top++;
    stack[top]=temp;
}
//pop
int pop()
{
    if (top == -1){
        printf("stack is empty");
        return -1;
    }
    else{
        return stack[top--];
    }
}
//precedence
int preced(char ch)
{   
    switch(ch){
        case '(':
            return 0;
        case '-':
        case '+':
            return 1;
        case '*':
        case '/':
            return 2;
    }  
}

int main()
{
    char infix[MAX_SIZE];
    top=-1;
    printf("enter the string: ");
    scanf("%s",infix);
    char postfix[MAX_SIZE];
    int i=0,j=0;
    while (infix[i]!='\0'){

        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ( stack[top] != '('){
                postfix[j++] = stack[top];
                pop();
            }
            pop();
        }
        else {
            while (preced(stack[top])>= preced(infix[i])){
                postfix[j++] = stack[top];
                pop();
            }
            push(infix[i]);
        }
            i++;
    }
        while(top>-1){
               postfix[j++]=stack[top];
               pop();
        }
    for (int i=0;i<j;i++)
    {
        printf("%c", postfix[i]);
    }
    return 0;
}