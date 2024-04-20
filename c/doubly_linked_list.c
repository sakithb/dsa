#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} DoublyLList;

DoublyLList *llist_new() {
    DoublyLList *ll = malloc(sizeof(DoublyLList));
    ll->head = NULL;
    ll->tail = NULL;

    if (ll == NULL) {
        return NULL;
    }

    return ll;
}

void llist_free(DoublyLList *ll) {
    Node *n = ll->head;
    while (n != NULL) {
        free(n);
        n = n->next;
    }

    free(ll);
}

void llist_append(DoublyLList *ll, int data) {
    Node *n = malloc(sizeof(Node));

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

void llist_prepend(DoublyLList *ll, int data) {
    Node *n = malloc(sizeof(Node));

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

int llist_pop(DoublyLList *ll) {
    if (ll->head == NULL && ll->tail == NULL) {
        return INT_MAX;
    }

    int data = ll->tail->data;
    ll->tail = ll->tail->prev;
    free(ll->tail->next);

    return data;
}

int llist_shift(DoublyLList *ll) {
    if (ll->head == NULL && ll->tail == NULL) {
        return INT_MAX;
    }

    int data = ll->head->data;
    ll->head = ll->head->next;
    free(ll->head->prev);

    return data;
}

void llist_insert(DoublyLList *ll, int index, int data) {
    Node *cur = ll->head;
    while (index > 0 && cur != NULL) {
        cur = cur->next;
        index--;
    }

    if (cur == NULL) {
        return;
    }

    Node *n = malloc(sizeof(Node));
    if (n == NULL) {
        return;
    }

    n->data = data;

    if (ll->head == cur) {
        ll->head = n;
    } else {
        cur->prev->next = n;
        n->prev = cur->prev;
    }

    if (ll->tail == cur) {
        ll->tail = n;
    }

    cur->prev = n;
    n->next = cur;
}

void llist_delete(DoublyLList *ll, int index) {
    Node *cur = ll->head;
    while (index > 0 && cur != NULL) {
        cur = cur->next;
        index--;
    }

    if (cur == NULL) {
        return;
    }

    if (ll->head == cur) {
        ll->head = cur->next;
    } else {
        cur->prev->next = cur->next;
    }

    if (ll->tail == cur) {
        ll->tail = cur->prev;
    } else {
        cur->next->prev = cur->prev;
    }

    free(cur);
}

int main() {
    DoublyLList *ll = llist_new();

    for (int i = 1; i <= 20; i++) {
        llist_append(ll, i);
    }

    for (int i = 0; i < 10; i++) {
        llist_insert(ll, i, i * 10);
    }

    Node *n = ll->head;
    while (n != NULL) {
        printf("%d\n", n->data);
        n = n->next;
    }

    return 0;
}
