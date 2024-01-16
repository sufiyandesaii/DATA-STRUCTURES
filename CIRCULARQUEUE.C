#include<stdio.h>
#define size 5

int queue[size];
int front=-1;
int rear =-1;


void enqueue(int a)
{
    if((front==rear+1) || (front==0 && rear==size-1))
    {
        printf("Queue overflow\n");
        return;
    }
    else
    {
        if(front==-1)
            front=0;
        rear=(rear+1)%size;
        queue[rear]=a;
    }
}

void dequeue()
{
    if(front==-1)
    {
        printf("Queue Empty\n");
    }
    else
    {
        int a=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;

        }
        else
        {
            front=(front+1)%size;

        }
        printf("Deleted element=%d\n",a);
        return(a);
    }
}

void display()
{
    if(front==-1)
    {
        printf("Queue Empty\n");
        return;
    }
    else
    {
        int i;
        printf("\nFront=%d", front);
        printf("\nItems=");
        for(i=front;i!=rear;i=(i+1)%size)
        {
            printf("%d",queue[i]);
        }
        printf("%d",queue[i]);
        printf("\nRear=%d",rear);
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
               enqueue(a);
               display();
               break;
        
        case 2:dequeue();
               display();
               break;
        
        case 3:display();
               break;
        }
    }

}