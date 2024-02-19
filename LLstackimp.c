#include<stdio.h>
#include<stdlib.h>
#define pf printf
#define sf scanf

struct node{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp,*temp1;


void push()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    pf("Enter the data to be pushed into the stack:");
    sf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;

}
 void display()
 {
     pf("\nThe stack you have created is:\n");
     temp=head;
     while(temp!=NULL)
    {
        pf("%d\n",temp->data);
        temp=temp->next;
    }
}

void pop()
{
    if(head==NULL)
        pf("\nThe stack is empty");
    else
    {
        temp=head;
        head=temp->next;
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
    case 1: push();
            display();
            break;
    case 2: pop();
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