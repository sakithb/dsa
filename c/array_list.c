#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    size_t length;
    size_t capacity;
    int* items;
} ArrayList;

ArrayList* arraylist_new() {
    ArrayList* list = malloc(sizeof(ArrayList));
    list->capacity = 10;
    list->length = 0;
    list->items = malloc(10 * sizeof(int));

    return list;
}

void arraylist_free(ArrayList *list) {
    if (list->items != NULL) {
        free(list->items);
    }

    free(list);
}

int arraylist_append(ArrayList *list, int item) {
    if (list->length >= list->capacity) {
        list->capacity *= 2;
        list->items = realloc(list->items, list->capacity * sizeof(int));
    }

    if (list->items == NULL) {
        return 0;
    }

    list->items[list->length] = item;
    list->length++;

    return 1;
}

int arraylist_pop(ArrayList *list) {
    if (list->length <= 0) {
        return INT_MAX;
    }

    list->length--;
    return list->items[list->length];
}

int arraylist_get(ArrayList *list, int index) {
    if (index >= list->length) {
        return INT_MAX;
    }

    return list->items[index];
}

int arraylist_put(ArrayList *list, int index, int item) {
    if (index >= list->length) {
        return 0;
    }

    list->items[index] = item;
    return 1;
}

int main() {
    ArrayList* l = arraylist_new();

    for (int i = 0; i < 20; i++) {
        arraylist_append(l, i);
    }

    for (int i = 0; i < 10; i++) {
        arraylist_put(l, i, 10 - i);
    }

    for (int i = 0; i < 20; i++) {
        int num = arraylist_get(l, i);
        printf("%d\n", num);
    }

    arraylist_free(l);
    return 0;
}
