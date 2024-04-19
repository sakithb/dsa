#include <stdlib.h>
#include <stdio.h>

void merge_arr(int *l_arr, int *r_arr, size_t l_len, size_t r_len) {
    int li, ri, ti;
    int tmp[l_len + r_len] = {};

    li = ri = ti = 0;

    while (li < l_len && ri < r_len) {
        if (l_arr[li] < r_arr[ri]) {
            tmp[ti] = l_arr[li];
            li++;
        } else {
            tmp[ti] = r_arr[ri];
            ri++;
        }

        ti++;
    }

    while (li < l_len) {
        tmp[ti] = l_arr[li];
        li++;
        ti++;
    }

    while (ri < r_len) {
        tmp[ti] = r_arr[ri];
        ri++;
        ti++;
    }

    li = ri = ti = 0;

    while (ti < l_len + r_len) {
        if (li < l_len) {
            l_arr[li] = tmp[ti];
            li++;
        } else {
            r_arr[ri] = tmp[ti];
            ri++;
        }

        ti++;
    }
}

void merge_sort(int *arr, size_t len) {
    if (len == 1) {
        return;
    }

    size_t l_len = len / 2;
    size_t r_len = len - l_len;

    int *l_arr = arr;
    int *r_arr = l_arr + l_len;

    merge_sort(l_arr, l_len);
    merge_sort(r_arr, r_len);

    merge_arr(l_arr, r_arr, l_len, r_len);
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

    merge_sort(arr, argc - 1);

    for (int i = 0; i < argc - 1; i++) {
        if (i == argc - 2) {
            printf("%d\n", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
