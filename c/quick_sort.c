#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *arr, int len) {
    if (len <= 1) {
        return;
    }

    int hi = len - 1;
    int pivot = arr[hi];
    int last_lo = -1;

    for (int i = 0; i <= hi; i++) {
        if (arr[i] < pivot) {
            last_lo++;

            int tmp = arr[i];
            arr[i] = arr[last_lo];
            arr[last_lo] = tmp;
        }
    }

    int pivot_i = last_lo + 1;

    arr[hi] = arr[pivot_i];
    arr[pivot_i] = pivot;

    quick_sort(arr, pivot_i);
    quick_sort(&arr[pivot_i + 1], hi - pivot_i);
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

    quick_sort(arr, argc - 1);

    for (int i = 0; i < argc - 1; i++) {
        if (i == argc - 2) {
            printf("%d\n", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
