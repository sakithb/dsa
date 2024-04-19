#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, size_t len) {
    if (len == 1) {
        return;
    }

    for (int i = 0; i < len - 1; i++) {
        int curr = arr[i];
        int next = arr[i + 1];

        if (curr > next) {
            arr[i + 1] = curr;
            arr[i] = next;
        }
    }

    bubble_sort(arr, len - 1);
}

int main(int argc, char** argv) {
    int arr[argc - 1] = {};
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);    
        if (num == 0 && argv[i][0] != '0') {
            printf("Arguments expected: <...array>");
            return 0;
        }

        arr[i - 1] = num;
    }

    bubble_sort(arr, argc - 1);

    for (int i = 0; i < argc - 1; i++) {
        if (i == argc - 2) {
            printf("%d\n", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
