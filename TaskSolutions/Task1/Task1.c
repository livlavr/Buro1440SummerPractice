#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FREE(ptr)\
    free(ptr);   \
    ptr = NULL

typedef struct Part{
    int left;
    int right;
} Part;

int rightComparing(const void* first_part, const void* second_part);
int taskSolution  (int n);

int main() {
    int n = 0;
    scanf("%d", &n);

    int result = taskSolution(n);

    printf("%d\n", result);
}

int rightComparing(const void* first_part, const void* second_part) {
    assert(first_part);
    assert(second_part);

    Part* first  = (Part*)first_part;
    Part* second = (Part*)second_part;

    return  first->right - second->right;
}

int taskSolution(int n) {
    assert(n > 0);

    Part* parts_array = (Part*)calloc(n, sizeof(Part));
    assert(parts_array);

    int x = 0;
    int y = 0;
    int scanf_status = 0;
    for(int i = 0; i < n; i++) {
        int scanf_status = scanf("%d %d", &x, &y);
        assert(scanf_status == 2);

        parts_array[i].left  = x;
        parts_array[i].right = y;
    }

    qsort(parts_array, n, sizeof(Part), rightComparing);

    int result = 0;
    int right_coord = 0;
    int i = 0;
    while(i < n) {
        right_coord = parts_array[i].right;
        i++;
        result++;
        while(parts_array[i].left <= right_coord && i < n) {
            i++;
        }
    }

    free(parts_array);

    return result;
}
