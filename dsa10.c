#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node *left;
 struct Node *right;
};
struct Node *createNode(int value) {
 struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
 if (newNode == NULL) {
 printf("Memory allocation failed.\n");
 exit(1);
 }
 newNode->data = value;
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
}
struct Node *insertNode(struct Node *root, int value) {
 if (root == NULL) {
 return createNode(value);
 }
 if (value < root->data) {
 root->left = insertNode(root->left, value);
 } else if (value > root->data) {
 root->right = insertNode(root->right, value);
 }
 return root;
}
void inorderTraversal(struct Node *root) {
 if (root != NULL) {
 inorderTraversal(root->left);
 printf("%d ", root->data);
 inorderTraversal(root->right);
}
}
void preorderTraversal(struct Node *root) {
 if (root != NULL)
{
 printf("%d ", root->data);
 preorderTraversal(root->left);
 preorderTraversal(root->right);
}
}
void postorderTraversal(struct Node *root) {
 if (root != NULL) {
 postorderTraversal(root->left);
 postorderTraversal(root->right);
 printf("%d ", root->data);
}
}
int searchBST(struct Node *root, int key) {
 if (root == NULL) {
 return 0;
}
 if (root->data == key) {
 return 1;
}
 if (key < root->data) {
 return searchBST(root->left, key);
 } else {
 return searchBST(root->right, key);
}
}
int main() {
 struct Node *root = NULL;
 int choice, key;
 int values[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
 int numValues = sizeof(values) / sizeof(values[0]);
 for (int i = 0; i < numValues; i++) {
 root = insertNode(root, values[i]);
 }
 while (1) {
 printf("\nBinary Search Tree (BST) Operations Menu:\n");
 printf("1. Inorder Traversal\n");
 printf("2. Preorder Traversal\n");
 printf("3. Postorder Traversal\n");
 printf("4. Search for a Key\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Inorder Traversal: ");
 inorderTraversal(root);
 printf("\n");
 break;
 case 2:
 printf("Preorder Traversal: ");
 preorderTraversal(root);
 printf("\n");
 break;
 case 3:
 printf("Postorder Traversal: ");
 postorderTraversal(root);
 printf("\n");
 break;
 case 4:
 printf("Enter the key to search: ");
 scanf("%d", &key);
 if (searchBST(root, key)) {
 printf("Key found in the BST.\n");
 } else {
 printf("Key not found in the BST.\n");
 }
 break;
 case 5:
 return 0;
 default:
 printf("Invalid choice. Please select a valid option.\n");
 }
 }
 return 0;
}
