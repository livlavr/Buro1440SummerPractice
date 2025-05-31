#include <stdio.h>
#include <stdlib.h>

int taskSolution();

int main() {
    int result = taskSolution();

    printf("%d\n", result);
}

int taskSolution() {
    int func_value_n_1 = 3;
    int func_value_n_2 = 1;
    int func_value     = 0;

    for (int n = 2; n < 59; n++) {
        func_value   = (5 * func_value_n_1 + func_value_n_2) % 100;
        func_value_n_2 = func_value_n_1;
        func_value_n_1 = func_value;
    }

    return func_value;
}
