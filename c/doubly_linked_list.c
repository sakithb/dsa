#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} DoublyLList;

DoublyLList* llist_new() {
    DoublyLList* ll = malloc(sizeof(DoublyLList));
    ll->head = NULL;
    ll->tail = NULL;

    if (ll == NULL) {
        return NULL;
    }

    return ll;
}


void llist_free(DoublyLList* ll) {
    Node* n = ll->head;
    while(n != NULL) {
        free(n);
        n = n->next;
    }

    free(ll);
}

void llist_append(DoublyLList* ll, int data) {
    Node* n = malloc(sizeof(Node));

    if (n == NULL) {
        return;
    }

    n->data = data;

    if (ll->head == NULL && ll->tail == NULL) {
        ll->head = ll->tail = n;
    } else {
        n->prev = ll->tail;
        ll->tail->next = n;
        ll->tail = n;
    }
}

void llist_prepend(DoublyLList* ll, int data) {
    Node* n = malloc(sizeof(Node));

    if (n == NULL) {
        return;
    }

    n->data = data;

    if (ll->head == NULL && ll->tail == NULL) {
        ll->head = ll->tail = n;
    } else {
        n->next = ll->head;
        ll->head->prev = n;
        ll->head = n;
    }
}

int llist_pop(DoublyLList* ll) {
    if (ll->head == NULL && ll->tail == NULL) {
        return INT_MAX;
    }

    int data = ll->tail->data;
    ll->tail = ll->tail->prev;
    free(ll->tail->next);

    return data;
}

int llist_shift(DoublyLList* ll) {
    if (ll->head == NULL && ll->tail == NULL) {
        return INT_MAX;
    }

    int data = ll->head->data;
    ll->head = ll->head->next;
    free(ll->head->prev);

    return data;
}

int main() {
    DoublyLList* ll = llist_new();

    for (int i = 0; i < 20; i++) {
        llist_append(ll, i);
    }

    Node* n = ll->head;
    while(n != NULL) {
        printf("%d\n", n->data);
        n = n->next;
    }

    return 0;
}
