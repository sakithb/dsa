#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *btree_new(int data) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
        return NULL;
    }

    n->data = data;
    return n;
}

void btree_traverse(Node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d\n", root->data);
    btree_traverse(root->left);
    btree_traverse(root->right);
}

Node *btree_insert_left(Node *root, int data) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
        return NULL;
    }

    n->data = data;
    root->left = n;

    return n;
}

Node *btree_insert_right(Node *root, int data) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
        return NULL;
    }

    n->data = data;
    root->right = n;

    return n;
}

int main() {
    Node *root = btree_new(3);

    Node* l = btree_insert_left(root, 1);
    Node* r = btree_insert_right(root, 2);
    Node* ll = btree_insert_left(l, 11);
    Node* lr = btree_insert_right(l, 12);
    Node* rl = btree_insert_left(r, 21);
    Node* rr = btree_insert_right(r, 22);
    btree_traverse(root);

    return 0;
}
