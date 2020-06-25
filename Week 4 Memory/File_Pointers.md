## File Pointers

* The file manipulation functions all live in stdio.h.
  * All of them accept `FILE*` as one of their parameters, except for the function `fopen()`, which is used to get a file pointer in the first place.
* Some of the most common file I/O functions: 
  * `fopen()`
  * `fclose()`
  * `fgetc()`
  * `fputc()`
  * `fread()`
  * `fwrite()`

<br />

#### fopen()

* Opens a file and returns a file pointer to it.
* Always check the return value to make sure you **don't get back NULL**.

```
FILE* ptr = fopen(<filename>, <operation>);

// Examples
FILE* ptr1 = fopen("file1.txt", "r");   // r for read
FILE* ptr2 = fopen("file2.txt", "w");   // w for write (will overwrite if file already exists)
FILE* ptr3 = fopen("file3.txt", "a");   // a for append (will add new value at the end of file)
```

<br />

#### fclose()

* Closes the file pointed to by the given file pointer.

```
fclose(<file pointer>);

// Example
fclose(ptr1);
```

<br />

#### fgetc()

* Reads and returns the next character from the file pointed to.
* Note: The operation of the file pointer passed in as a parameter **must be "r" for read**, or you will suffer an error.

```
char ch = fgetc(<file pointer>);

// Example
char ch = fgetc(ptr1);
```

<br />

* The ability to get single characters from files, if wrapped in a loop, means we could *read all the characters from a file* and print them to the screen, one-by-one, essentially.

```
char ch;
while((ch = fgetc(ptr)) != EOF)   // EOF = end of file character
  printf("%c", ch);
```

* We might put this in a file called cat.c, after the Linux command `cat` which essentially does just this.

<br />

#### fputc()

* Writes or appends the specified character to the pointed-to file.
* Note: The operation of the file pointer passed in as a parameter **must be "w" for write or "a" for append**, or you will suffer an error.

```
fputc(<character>, <file pointer>);

// Example
fputc('A', ptr2);   // overwrite A in ptr2 file
fputc('!', ptr3);   // write ! to the end of ptr3
```

<br />

* Now we can *read characters from files and write characters to another*.

```
char ch;
while((ch = fgetc(ptr)) != EOF)
  fputc(ch, ptr2);
```

* We might put this in a file called cp.c, after the Linux command `cp` which essentially does just this.

<br />

#### fread()

* Reads <qty> units of size <size> from the file pointed to and stores them in memory in a buffer (usually an array) pointed to by <buffer>.
* Note: The operation of the file pointer passed in as a parameter must be "r" for read, or you will suffer an error.

```
fread(<buffer>, <size>, <qty>, <file pointer>);   // going from file to buffer

// Example - buffer in the stack
int arr[10];
fread(arr, sizeof(int), 10, ptr);   // array is a pointer, so can be used as a buffer directly

// Example - buffer in the heap
double* arr2 = malloc(sizeof(double) * 80);
fread(arr2, sizeof(double), 80, ptr);

// Example - Treat fread just like a call to fgetc
char c;
fread(&c, sizeof(char), 1, ptr);   // c is not a pointer, so we have to use &c as a buffer
```

<br />

#### fwrite()

* Write <qty> units of size <size> to the file pointed to by reading them from a buffer (usually an array) pointed to by <buffer>.
* Note: The operation of the file pointer passed in as a parameter must be "w" for write or "a" for append, or you will suffer an error.

```
fwrite(<buffer>, <size>, <qty>, <file pointer>);   // going from buffer to file

// Example - buffer in the heap
double* arr2 = malloc(sizeof(double) * 80);
fwrite(arr2, sizeof(double), 80, ptr2);

// Example - write a single variable
char c;
fwrite(&c, sizeof(char), 1, ptr3);
```

<br />

#### Other Useful Functions

Function | Description
:---|:---
fgets()|Reads a full string from a file
fputs()|Writes a full string to a file
fprintf()|Writes a formatted string to a file
fseek()|Allows you rewind or fast-forward within a file
ftell()|Tells you at what (byte) position you are at within a file
feof()|Tells you whether you've read to the end of a file
ferror()|Indicates whether an error has occurred in working with a file


