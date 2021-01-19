## Pointers

**Pointers are just addresses**.

* A pointer, then, is a data item whose
  * *value* is a memory **address**
  * *type* describes **the data** located at that memory address

```
int k;   // Get a space for int k (4 bytes)
k = 5;   // Assign k to 5
int* pk;   // Get a space for pointer pk which points at an int
pk = &k;   // Assign pk to the address of k
k = *&k;   // Go to k's location and get the value at that location

int* pa, *pb, *pc;   // Need to keep typing * when creating pointers
```

<br />

#### Create A Pointer

* The simplest pointer available in C is the **NULL** pointer (points to nothing).
  * You should **always** set the value of the pointer to NULL when creating a pointer without setting its value immediately.
  * You can check whether a pointer is NULL using the equality operator (**==**).
* Another way to create a pointer is to simply **extract** the address of an already existing variable by using address extraction operator (**&**).
* An array's name is actually a pointer to its first element.

<br />

#### Functions

The main purpose of a pointer is to **allow us to modify or inspect the location to which it points**.
* We do this by **dereferencing** the pointer using the dereference operator (__*__).
  * It *"goes to the reference" and accesses the data at that memory location*.
* Pointers provide a way to **pass the actual variable itself** between functions.
  * Recall that we have passed all data **by value**, with one exception - **string**.
  * When we pass data by value, we only **pass a copy** of that data.
* Pointers allow data structures and/or variables to be shared among functions.
* Pointers make a computer environment more like the real world.

<br />

#### Memory

* Every file on your computer lives in your disk drive, a hard disk drive(HDD) or a solid-state drive(SSD).
* Disk drives are just storage space; we cannot directly work there. Manipulation and use of data can only take place in **RAM**(Random Access Memory), so we have to move data there.
* Memory is basically *a huge **array of byte-sized cells**(8-bit wide bytes)*.
  * Arrays not only are useful for storage of information but also for so-called **random access** by indicating which *index location* we want.
* Similarly, each location in memory has an **address**.

<br />

Data Type |Size (in bytes)
:---|:---
int | 4
char| 1
float| 4
double| 8
long long| 8
char* | 4 or 8 depends on system


