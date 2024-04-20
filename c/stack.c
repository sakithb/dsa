#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int data;
    struct Item *next;
} Item;

typedef struct {
    int length;
    Item *items;
} Stack;

Stack *stack_new() {
    Stack *s = malloc(sizeof(Stack));
    if (s == NULL) {
        return NULL;
    }

    s->length = 0;
    s->items = NULL;

    return s;
}

void stack_free(Stack *s) {
    Item *item = s->items;
    while (item != NULL) {
        free(item);
        item = item->next;
    }

    free(s);
}

void stack_push(Stack *s, int data) {
    Item *i = malloc(sizeof(Item));
    if (i == NULL) {
        return;
    }

    i->data = data;
    i->next = s->items;
    s->items = i;
    s->length++;
}

int stack_pop(Stack *s) {
    Item *tmp = s->items;
    int data = tmp->data;

    s->items = s->items->next;
    s->length--;

    free(tmp);
    return data;
}

int main() {
    Stack *s = stack_new();

    for (int i = 0; i < 10; i++) {
        stack_push(s, i);
    }

    printf("Length: %d - Peek: %d\n", s->length, s->items->data);

    while (s->length > 0) {
        int i = stack_pop(s);
        printf("popping %d\n", i);
    }

    return 0;
}
