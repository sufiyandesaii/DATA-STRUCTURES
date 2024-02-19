#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *createNode(int value)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;

}

void displayList(Node *head)
{
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

Node *sortList(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }


    int swapped;
    Node *temp;
    Node *end=NULL;

    do
    {

        swapped=0;
        temp=head;
        while(temp->next !=end)
        {
            if(temp->data > temp->next->data)
            {
                int tempData=temp->data;
                temp->data=temp->next->data;
                temp->next->data=tempData;
                swapped=1;

            }
            temp=temp->next;
        }
        end=temp;
    }while(swapped);

    return head;
}

Node *reverseList(Node *head)
{
    Node *prev=NULL;
    Node *current=head;
    Node *nextNode=NULL;

    while(current!=NULL)
    {
        nextNode=current->next;
        current->next=prev;
        prev=current;
        current=nextNode;
    }
    return prev;

}

Node *concatenatedLists(Node *list1,Node *list2)
{

    if(list1==NULL)
    {
       return list2;
    }

    Node *temp=list1;
    while(temp->next!=NULL)
    {
         temp=temp->next;
    }
    temp->next=list2;
    return list1;

}

int main()
{
    Node *list1=createNode(3);
    list1->next=createNode(1);
    list1->next->next=createNode(4);

    Node *list2=createNode(2);
    list2->next=createNode(5);

    printf("Original list 1:");
    displayList(list1);

    printf("Original list 2:");
    displayList(list2);

    list1=sortList(list1);
    printf("Sorted list 1:");
    displayList(list1);

    list1=reverseList(list1);
    printf("Reversed list 1:");
    displayList(list1);

    Node *Concatenated= concatenatedLists(list1,list2);
    printf("Concatenated List:");
    displayList(Concatenated);
    return 0;


}