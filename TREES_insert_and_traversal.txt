#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int data) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

struct node* insert(struct node* root, int data) {
  if (root == NULL) return newNode(data);
  if (data <= root->data) root->left = insert(root->left, data);
  else root->right = insert(root->right, data);
  return root;
}

void inorder(struct node* temp) {
  if (temp == NULL) return;
  inorder(temp->left);
  printf("%d ", temp->data);
  inorder(temp->right);
}

void preorder(struct node* temp) {
  if (temp == NULL) return;
  printf("%d ", temp->data);
  preorder(temp->left);
  preorder(temp->right);
}

void postorder(struct node* temp) {
  if (temp == NULL) return;
  postorder(temp->left);
  postorder(temp->right);
  printf("%d ", temp->data);
}

int main() {
  struct node* root = NULL;
  int data, choice;

  do {
    printf("Enter your choice:\n1. Insert\n2. Print Inorder\n3. Print Preorder\n4. Print Postorder\n5. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the value to be inserted: ");
        scanf("%d", &data);
        root = insert(root, data);
        break;
      case 2:
        printf("Inorder traversal of binary tree is \n");
        inorder(root);
        printf("\n");
        break;
      case 3:
        printf("Preorder traversal of binary tree is \n");
        preorder(root);
        printf("\n");
        break;
      case 4:
        printf("Postorder traversal of binary tree is \n");
        postorder(root);
        printf("\n");
        break;
      case 5:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 5);

  return 0;
}