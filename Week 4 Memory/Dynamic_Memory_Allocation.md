## Dynamic Memory Allocation

* We can use pointers to get access to a block of **dynamically-allocated memory** at runtime.
* Dynamically allocated memory comes from a pool of memory known as the **heap**.
* Prior to this point, all memory we've been working with has been coming from a pool of memory known as the **stack**.

<br />

### How to get ?

* We get this dynamically-allocated memory by making a call to the C standard library function `malloc()`, passing as its parameter the number of bytes requested.
* After obtaining memory for you (if it can), `malloc()` will **return a pointer to that memory**.
* If `malloc()` cannot give you memory, then it will hand you back **NULL**.

<br />

### Examples

```
// statically obtain an integer
int x;

// dynamically obtain an integer
int* px = malloc(sizeof(int));

```

```
// get an integer from the user
int x = GetInt();

// array of floats on the stack
float stack_array[x]

// array of floats on the heap
float* heap_array = malloc(x * sizeof(float));

```

<br />

### How to free memory?

* **Dynamically-allocated memory is not automatically returned** to the system for later use when the function in which it's created finishes execution.
* Failing to return memory back to the system when you're finished with it results in a **memory leak** which can compromise your system's performance.
* When you finish working with dynamically-allocated memory, you must `free()` it.

```
char* word = malloc(50 * sizeof(char));

// do stuff with word

// now we're done working with that block
free(word);
```

<br />

### Three golden rules

1. Every block of memory that you `malloc()` must subsequently be `free()`d.
2. Only memory that you `malloc()` should be `free()`d.
3. Do not `free()` a block of memory more than once.


