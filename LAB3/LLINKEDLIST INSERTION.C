#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};


struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List:\n ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


struct Node *insertatbeginning(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

void insertatend(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertatposition(struct Node *head, int position, int value)
{
    struct Node *newNode = createNode(value);
    struct Node *temp = head;
    int count = 1;

    while (temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


int main()
{
    struct Node *head = NULL;

    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    printf("Initial:\n ");
    displayList(head);

    head = insertatbeginning(head, 0);
    printf("After insertion at the beginning:\n ");
    displayList(head);


    insertatposition(head, 3, 10);
    printf("After insertion at position 3:\n ");
    displayList(head);


    insertatend(head, 20);
    printf("After insertion at the end:\n ");
    displayList(head);

    return 0;
}