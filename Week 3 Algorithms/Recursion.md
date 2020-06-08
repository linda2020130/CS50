## Recursion

**Recursion** occurs when a function or algorithm refers to itself.
* The technique of recursion is a very common way to implement such an "elegant" solution.
* In general, but not always, recursive functions replace loops in non-recursive functions.
* It's possible to have *more than one bases or recursive case*, if the program might recurse or terminate in different ways,
depending on the input being passed in.
  * **Multiple base cases**: The *Fibonacci number sequence* is defined as a(n) = a(n-1) + a(n-2) where a(0)=0 and a(1)=1.
  * **Multiple recursive cases**: The *Collatz conjecture*. (See below) 

<br />

### Example - Factorial Function

The **factorial function** `n!` is defined over all positive integers.

```
/*
fact(1) = 1
fact(2) = 2 * 1 = 2 * fact(1)
fact(3) = 3 * 2 * 1 = 3 * fact(2)
fact(4) = 4 * 3 * 2 * 1 = 4 * fact(3)
fact(5) = 5 * 4 * 3 * 2 * 1 = 5 * fact(4)
...
=> fact(n) = n * fact(n-1)
*/

int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n-1);
}
```

Equivalently,

```
int fact2(int n)
{
    int product = 1;
    while(n > 0)
    {
        product *= n;
        n--;
    }
    return product;
}
```

<br />

### Example - The Collatz Conjecture

**The Collatz conjecture** is applied to positive integers and speculates that it is always possible to get
" back to 1" if you follow these steps:
* If n is 1, stop.
* Otherwise, if n is even, repeat this process on n/2.
* Otherwise, if n is odd, repeat this process on 3n + 1.

A **recursive function** `collatz(n)` calculates how many steps it takes to get to 1.

```
int collatz(int n)
{
    // base case
    if (n == 1)
        return 0;
    // even numbers
    else if ((n % 2) == 2)
        return 1 + collatz(n/2);
    // odd numbers
    else
        return 1 + collatz(3*n + 1);
}
```


