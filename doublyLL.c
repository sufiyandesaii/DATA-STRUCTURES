#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNodeToLeft(struct Node* head, struct Node* target, int data) 
{
    struct Node* newNode = createNode(data);
    if (target->prev != NULL) 
    {
        target->prev->next = newNode;
        newNode->prev = target->prev;
    } 
    else 
    {
        head = newNode;
    }
    newNode->next = target;
    target->prev = newNode;
}


void deleteNode(struct Node* head, int value) 
{
    struct Node* current = head;
    while (current != NULL) 
    {
        if (current->data == value) 
        {
            if (current->prev != NULL) 
            {
                current->prev->next = current->next;
            } 
            else 
            {
                head = current->next;
            }
            if (current->next != NULL) 
            {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
    printf("Node with value %d not found\n", value);
}


void displayList(struct Node* head) 
{
    printf("Doubly Linked List: ");
    while (head != NULL) 
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node* head = NULL;


    head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;

    displayList(head);

    insertNodeToLeft(head, head->next, 10);
    printf("After insertion:\n");
    displayList(head);

    deleteNode(head, 2);
    printf("After deletion:\n");
    displayList(head);

    return 0;
}