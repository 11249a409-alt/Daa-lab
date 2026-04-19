#include <stdio.h>

int fib_recursive(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fib_recursive(n-1) + fib_recursive(n-2);
}

int fib_iterative(int n)
{
    int a = 0, b = 1, c, i;

    if(n == 0)
        return 0;

    for(i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Fibonacci using recursion = %d\n", fib_recursive(n));
    printf("Fibonacci using iteration = %d\n", fib_iterative(n));

    return 0;
}

