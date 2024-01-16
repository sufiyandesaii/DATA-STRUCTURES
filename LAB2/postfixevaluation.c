//SUFIYAN DESAI
#include<stdio.h>
#include<string.h>
#include<ctype.h> 

#define max 20

int stack[20];
int top=-1;

void push(int a)
{
    stack[++top]=a;
}

int pop()
{
    return stack[top--];
}

void main()
{
    char postfix[max];
    printf("Enter postfix expression:");
    scanf("%s",postfix);

    int res=0,a,b;   

    for(int i=0;i<strlen(postfix);i++)
    {
        if(isalnum(postfix[i]))
            push(postfix[i]-'0');
        else
        {
            b=pop();
            a=pop();
            switch (postfix[i])
            {
            case '+':push(a+b);
                     break;
            case '-':push(a-b);
                     break; 
            case '*':push(a*b);
                     break;
            case '/':push(a/b);
                     break;
            case '^':push(a^b);
                     break;           
            }
        }
    }
    res=pop();
    printf("%s=%d",postfix,res);
}
