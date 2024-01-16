#include<stdio.h>
#define size 30

int queue[size];
int front=-1;
int rear=-1;


void insert(int a)
{
    if(rear==size-1)
    {
        printf("Queue overflow\n");
        return;
    }
    else
    {
        if(front==-1)
            front=0;
        queue[++rear]=a;
    }
}

void delete()
{
    if(front==-1||front>rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        front++;
    }
}

void display()
{
    if(front==-1)
    {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue:");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
}


void main()
{
    int choice;
    int a;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\nChoice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:printf("Enter an element:");
               scanf("%d",&a);
               insert(a);
               display();
               break;
        
        case 2:delete();
               display();
               break;
        
        case 3:display();
               break;
        }
    }

}