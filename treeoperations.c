#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* create(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL)
        return create(data);
    if (data < root->data) 
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void in(Node* root) {
    if (root != NULL) {
        in(root->left);
        printf("%d ", root->data);
        in(root->right);
    }
}

void pre(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        pre(root->left);
        pre(root->right);
    }
}

void post(Node* root) {
    if (root != NULL) {
        post(root->left);
        post(root->right);
        printf("%d ", root->data);
    }
}

Node* min(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* delete(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data) 
        root->right = delete(root->right, data);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = min(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = NULL;

    root = insert(root, 45);
    insert(root, 39);
    insert(root, 56);
    insert(root, 12);
    insert(root, 54);
    insert(root, 78);
    insert(root, 10);
    insert(root, 34);
    insert(root, 67);
    insert(root, 89);
    insert(root, 32);
    insert(root, 81);

    printf("Initial\n");
    printf("In order:   "); in(root);
    printf("\n");
    printf("Pre order:  "); pre(root);
    printf("\n");
    printf("Post order: "); post(root);
    printf("\n\n");

    printf("Deleting 45\n");
    root = delete(root, 45);

    printf("\nAfter deleting 45\n");
    printf("In order:   "); in(root);
    printf("\n");
    printf("Pre order:  "); pre(root);
    printf("\n");
    printf("Post order: "); post(root);
    printf("\n\n");

    printf("Inserting 11, 22, 33, 44, 55, 66, 77\n\n");
    root = insert(root, 11);
    root = insert(root, 22);
    root = insert(root, 33);
    root = insert(root, 44);
    root = insert(root, 55);
    root = insert(root, 66);
    root = insert(root, 77);

    printf("After adding 11, 22, 33, 44, 55, 66, 77\n");
    printf("In order:   "); in(root);
    printf("\n");
    printf("Pre order:  "); pre(root);
    printf("\n");
    printf("Post order: "); post(root);
    printf("\n\n");

    return 0;
}
