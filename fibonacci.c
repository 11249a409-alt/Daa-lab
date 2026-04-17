## **AIM**

To write a C program to find the **nth Fibonacci number** using both **recursion** and **iterative method**.

---

## **ALGORITHM**

### **Recursive Method**

1. Start the program.
2. Read the value of `n`.
3. Define recursive function:

   * If `n == 0`, return 0
   * If `n == 1`, return 1
   * Else return `fib(n-1) + fib(n-2)`
4. Print the result.

### **Iterative Method**

1. Initialize `a = 0`, `b = 1`.
2. Loop from 2 to `n`:

   * `c = a + b`
   * Update `a = b`, `b = c`
3. Print the result.
4. Stop the program.

---

## **SOURCE CODE**

```c id="f5m2zb"
#include <stdio.h>

// Recursive function
int fib_recursive(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fib_recursive(n-1) + fib_recursive(n-2);
}

// Iterative function
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

    printf("Fibonacci (Recursive) = %d\n", fib_recursive(n));
    printf("Fibonacci (Iterative) = %d\n", fib_iterative(n));

    return 0;
}
```

---

## **SAMPLE OUTPUT**

```id="7hz5hs"
Enter n: 6
Fibonacci (Recursive) = 8
Fibonacci (Iterative) = 8
```

---

## **RESULT**

The program successfully calculates the **nth Fibonacci number** using both recursive and iterative methods.

* Recursive method is simple but inefficient (**O(2ⁿ)** time complexity).
* Iterative method is efficient (**O(n)** time complexity).

