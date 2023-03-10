#include <stdio.h>

int fibonacci(int max_fib)
{

    return (max_fib > 2) ? fibonacci(max_fib - 1) + (fibonacci(max_fib - 2)) : 1;
}

int main(void)
{
    int fib;
    fib = fibonacci(5);
    printf("%i\n", fib);
    return (1);
}
