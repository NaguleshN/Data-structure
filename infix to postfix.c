#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10
int stack[10];
int top = -1;
//push
void push(int temp)
{
    top++;
    stack[top]=temp;
}
//pop
void pop()
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
int precedence(char ch)
{ 
    if(ch == '(')
        return 0;
    else if (ch== '-' || ch=='+' )
        return 1;
    else if (ch== '*' || ch=='/' )
        return 2;
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
            }pop();
        }
        else {
            while (precedence(stack[top])>= precedence(infix[i])){
                postfix[j++] = stack[top];
                pop();
            }
            push(infix[i]);
        }
            i++;
    }
        while(top!=-1){
               postfix[j++]=stack[top];
               pop();
        }
    printf("\n%s\n", postfix);
    return 0;
}