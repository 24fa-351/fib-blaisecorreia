#include <stdio.h>
#include <stdlib.h>


int fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int fib_iterative(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, next;
    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <integer> <r/i> <filename>\n", argv[0]);
        return 1;
    }

   
    int num = atoi(argv[1]);

   
    FILE *file = fopen(argv[3], "r");
    if (!file) {
        printf("Error: Could not open file %s\n", argv[3]);
        return 1;
    }

    int file_num;
    fscanf(file, "%d", &file_num);
    fclose(file);

    int N = num + file_num;

    
    int result;
    if (argv[2][0] == 'r') {
        result = fib_recursive(N);
    } else if (argv[2][0] == 'i') {
        result = fib_iterative(N);
    } else {
        printf("Error: Invalid method. Use 'r' for recursive or 'i' for iterative.\n");
        return 1;
    }

   
    printf("The %dth Fibonacci number is: %d\n", N, result);

    return 0;
}
