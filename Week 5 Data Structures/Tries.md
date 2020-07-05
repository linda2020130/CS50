## Tries

Tries combine *structures and pointers* together to store data in an interesting way.
* The data to be searched for in the trie is now a roadmap.
  * If you can follow the map from beginning to end, the data exists in the trie.
  * If you can't, it doesn't.
* Unlike with a hash table, there are **no collisions**, and no two pieces of data (unless they are identical) have the same path.


<br />

### Example

Let's map key-value pairs where the keys are four-digit years (YYYY) and the values are names of universities founded during those years. 
* In a trie, the paths from a central **root** node to a **leaf** node (where the school names would be), would be labeled with digits of the year.
* Each node on the path from root to leaf could have 10 pointers emanating from it, one for each digit.

```
typedef struct _trie
{
    char university[20];
    struct _trie* paths[10];
}
trie;
```

![trie](https://github.com/linda2020130/Notes_CS50/blob/master/Pictures/tries.PNG)
