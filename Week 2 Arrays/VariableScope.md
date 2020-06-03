## Variables and Scope

**Scope** is a characteristic of a variable that defines from *which functions that variable may be accessed*.
* **Local variables** can only *be accessed **within** the functions* in which they are created.
* **Global variables** can *be accessed by **any*** function* in the program.

<br />

### Local Variables

`x` is **local** to the function triple(). No other function can refer to that variable, not even main(). `result` is **local** to main().

```
int main(void)
{
    int result = triple(5);
}

int triple(int x)
{
    return x * 3;
}
```

* For the most part, local variables in C are **passed by value** in function calls.
* When a variable is *passed by value*, the **callee** receives *a copy of the passed variable*, not the variable itself.
* That means that the variable in the **caller** is unchanged unless overwritten.

 ```
 int main(void)
 {
    int foo = 4;
    triple(foo);
    printf("%i", foo);   // Output 4
    foo = triple(foo);
    printf("%i", foo);   // Output 12
 }
 
 int triple(int x)
 {
    return x *= 3;
 }
 ```

<br />

### Global Variables

If a variable is declared **outside of all functions**, then it is a **global** variable.

```
#include <stdio.h>

float global = 0.5050;

int main(void)
{
    triple();
    printf("%f\n", global);
}

void triple(void)
{
    global *= 3;
}

```

<br />

### Other Example

It is okay to have the same variable name appears in multiple functions, as long as the variables exist in different scopes.

```
int increment(int x);

int main(void)
{
    int x = 1;
    int y;
    y = increment(x);
    printf("x is %i, y is %i\n", x, y);
}

int increment(int x)
{
    x++;
    return x;
}

/*
Output:
x is 1, y is 2
*/
```

