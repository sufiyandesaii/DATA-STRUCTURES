//SUFIYAN DESAI
#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
int top = -1;
int inp_array[SIZE];
void push();
void pop();
void show();

void main()
{
    int ch;
    while (1)
    {
        printf("Operations on the stack:\n");
        printf("1.Push the element\n2.Pop the element\n3.Show\n4.End\n");
        printf("Enter the choice:\n ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}

void push()
{
    int x;
    if (top == SIZE - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter the element to be added in the stack:\n ");
        scanf("%d", &x);
        top = top + 1;
        inp_array[top] = x;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Popped element: %d\n", inp_array[top]);
        top = top - 1;
    }
}
void show()
{
    if (top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Elements in the stack are: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", inp_array[i]);
    }
}
