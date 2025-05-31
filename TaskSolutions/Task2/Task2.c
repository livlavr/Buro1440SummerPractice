#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static const int ALPHABET_LENGTH = 26;

#define FREE(ptr)\
    free(ptr);   \
    ptr = NULL

int taskSolution(int n);

int main() {
    int n = 0;
    scanf("%d", &n);

    int result = taskSolution(n);

    if(result == -1) {
        printf("NONE\n");
    } else {
        printf("%d\n", result);
    }
}

int taskSolution(int n) {
    if(n <= 0) {
        return -1;
    }

    int  result = 0;
    int  found_counter = 0;

    int* found_flags = (int*)calloc(ALPHABET_LENGTH, sizeof(int));
    assert(found_flags);

    int input_value = 0;
    for(int i = 0; i < n; i++) {
        int scanf_status = scanf("%d", &input_value);
        assert(scanf_status == 1);

        if(found_counter < ALPHABET_LENGTH) {
            result++;
        }
        if(found_flags[input_value - 1] == 0) {
            found_flags[input_value - 1] = 1;
            found_counter++;
        }
    }

    if(found_counter < ALPHABET_LENGTH) {
        result = -1;
    }

    free(found_flags);

    return result;
}
