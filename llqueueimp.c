
#include<stdio.h>
#include<stdlib.h>
#define pf printf
#define sf scanf

struct node{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp,*temp1;


void pushqueue()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    pf("Enter the data to be pushed into the queue:");
    sf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;

}
 void display()
 {
     pf("\nThe queue you have created is:\n");
     temp=head;
     while(temp!=NULL)
    {
        pf("\t%d",temp->data);
        temp=temp->next;
    }
}

void popqueue()
{
    if(head==NULL)
        pf("\nThe queue is empty");
    else
    {
        temp=temp1=head;
        while(temp->next!=NULL)
            {
            temp1=temp;
            temp=temp->next;
            }
        temp1->next=NULL;
        free(temp);
    }

 }

 int main()
 {
 int ch;

 while(1)
    {
         pf("\n1.Push\n2.Pop\n3.Display\n4.Exit Menu\nChoice:");
            sf("%d",&ch);

 switch(ch)
        {
    case 1: pushqueue();
            display();
            break;
    case 2: popqueue();
            display();
            break;
    case 3: display();
            break;
    case 4: return 0;
    default:
            pf("\nInvalid input--try again\n\n\n");
        }
    }

 }