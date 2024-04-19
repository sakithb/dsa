#include <stdlib.h>
#include <stdio.h>

int* binary_search(int needle, int *arr, size_t len) {
    if (len == 0) {
        return NULL;
    }

    size_t new_len = len / 2;
    int *pivot = arr + new_len;

    if (*pivot == needle) {
        return pivot;
    } else if (*pivot > needle) {
        return binary_search(needle, arr, pivot - arr);
    } else {
        return binary_search(needle, pivot + 1, len - new_len - 1);
    }
}

int main(int argc, char** argv) {
    if (argc == 1) {
        printf("Expected arguments: <needle> <...array>\n");
        return 2;
    }

    int needle = atoi(argv[1]);
    if (needle == 0 && argv[1][0] != '0') {
        printf("Expected arguments: <needle> <...array>\n");
        return 2;
    }

    int arr[argc - 2] = {};
    for (int i = 2; i < argc; i++) {
        int num = atoi(argv[i]);
        if (num == 0 && argv[i][0] != '0') {
            printf("Expected arguments: <needle> <...array>\n");
            return 2;
        }

        arr[i - 2] = num;
    }

    int *result = binary_search(needle, arr, argc - 2);
    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%d\n", *result);
    }

    return 0;
}
