#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int info;
    struct node* rcl;
    struct node* lcl;
} node;


node* createBinaryTree() {
    int data;
    node* newNode;

    printf("Enter data (or -1 for NULL): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    newNode = (node*)malloc(sizeof(node));
    newNode->info = data;

    printf("Enter left child of %d: \n", data);
    newNode->lcl = createBinaryTree();

    printf("Enter right child of %d: \n", data);
    newNode->rcl = createBinaryTree();

    return newNode;
}

void printBinaryTree(node* root, int depth) {
    if (root == NULL) {
        return;
    }

    //Print right child
    printBinaryTree(root->rcl, depth + 1);

    //Indentation for the current node
    for (int i = 0; i < depth; i++) {
        printf("   ");
    }

    //Print the current node's value
    printf("%d\n", root->info);

    //Print left child
    printBinaryTree(root->lcl, depth + 1);
}

int main() {
    node* root = createBinaryTree();

    printf("Binary Tree in the specified format: \n");
    printBinaryTree(root, 0);

    return 0;
}
