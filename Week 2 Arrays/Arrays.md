## Arrays

* A fundamental **data structure**.
* To hold values of the **same type** at **contiguous memory locations**.
* If an array consists of **n** elements, the first element is located at **index 0**. 
The last element is located at **index (n-1)**.
* C will not prevent you from going **"out of bounds"** of your array.
* Arrays can consist of more than a single dimension.
* We can treat individual elements of arrays as variables, we **CANNOT treat entire arrays themselves as variables**.
For example, we ***CANNOT assign one array to another** using the assignment operator*. Instead, we must use a loop to copy over the elements one at a time.

```
int foo[5] = { 1, 2, 3, 4, 5};
int bar[5];

for (int i = 0; i < 5; i++)
{
  bar[i] = foo[i];
}
```

<br />

### Array declarations 
`type name[size];`
1. The **type** is what kind of variables each element of the array will be.
2. The **name** is what you want to call your array.
3. The **size** is how many elements you would like your array to contain.

<br />

### Examples
* Instantiation Syntax: `bool truthtable[3] = { false, true, true};` or 
`bool truthtable[] = { false, true, true};`
* Individual Element Syntax:
```
bool truthtable[3];
truthtable[0] = false;
truthtable[1] = true;
truthtable[2] = true;
```
* 10X10 Grid of Cells: `bool battleship[10][10];`

<br />

### Call by Value vs. Call by Reference

* Most variables in C are **passed by value** in function calls. That is, making a copy of the variable 
that's being passed in the callee function(the function receiving the variable) doesn't get the variable
itself, **it gets its own local copy of it** to work with.
* Arrays are **passed by reference**. That is, the **callee receives the actual array**, *not* a copy of it.

```
void set_array(int array[4]);
void set_int(int x);

int main(void)
{
  int a = 10;
  int b[4] = { 0, 1, 2, 3};
  set_int(a);
  set_array(b);
  printf("%d %d\n", a, b[0]);
}

void set_array(int array[4])
{
  array[0] = 22;
}

void set_int(int x)
{
  x = 22;
}

/*
output:
10, 22
*/
```
