#include <stdio.h>
#define max_length 10
int stack[max_length],top;

void push(int temp){
    stack[++top]=temp;
} 

int pop(){
return stack[top--];
}

int main(){
top=-1;
char postfix[max_length];
printf("enter the postfix expression: ");
scanf("%s",postfix);
int i=0;
while (postfix[i]!='\0')
{
    if (isdigit(postfix[i]))
    {
        int d;
        d=postfix[i]-'0';
        push(d);
    }
    else{
    int a,b,c;
    switch(postfix[i])
    {
        case '+' :
            a=pop();
            b=pop();
            c=a+b;
            push(c);

            break;
        case '-':
            a=pop();
            b=pop();
            c=b-a;
            push(c);
            break;
        case '*':
            a=pop();
            b=pop();
            c=a*b;
            push(c);
            break;
        case '/':
            a=pop();
            b=pop();
            c=b/a;
            push(c);
            break;
    }
    }
    i++ ;
}
printf("\n%d",stack[0]);
}
