## Hash Tables

A hash table amounts to a combination of two things with which we're quite familiar.
  1. First, a **hash function**, which returns an nonnegative integer value called a *hashed code*.
  2. Second, an **array** capable of storing data of the type we wish to place into the data structure.
* The idea is that we run our data through the hash function, and then store the data in the element of the array represented by the returned hash code.
* A **collision** occurs when two pieces of data, when run through the hash function, yield the same hash code.

<br />

### Hash Functions

How to define a hash function? -> Really no limit to the number of possible hash functions.
* A good hash function should:
  * Use only the data being hashed
  * Use all of the data being hashed
  * Be deterministic (i.e. always got the same hash code if inputting the same data)
  * Uniformly distribute data
  * Generate very different hash codes for very similar data

<br />

### Collisions

How to resolve collisions?
* **Linear probing**
  * Try to place the data in the next consecutive element in the array (wrapping around to the beginning if necessary) until we find a vacancy.
  * Subject to a problem called **clustering**. We can only store as much data as we have locations in our array.
  
* **Chaining** (Better)
  * If each element of the array is **a pointer** to the head of a linked list, then multiple pieces of data can yield the same hash code and we'll be able to store it all!
  * We know from experience with linked lists that insertion (and creation, if necessary) into a linked list is an O(1) operation (insert *at the beginning* of the linked list).
  * For lookup, we only need to search through what is hopefully a small list, since we're distributing what would otherwise be one huge list across n lists.
  
<br />

![hash table](https://github.com/linda2020130/Notes_CS50/blob/master/Pictures/hash_table.PNG)



