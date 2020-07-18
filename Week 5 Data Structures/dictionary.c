// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];

// Size counter
unsigned int size_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Hash word to obtain a hash value
    int hash_value = hash(word);
    // Linked list with NULL pointer
    if (table[hash_value] == NULL)
    {
        return false;
    }
    // Set a variable to store current node
    node *cursor = table[hash_value];
    // Check if value of current node is the same as word
    while (strcasecmp(cursor->word, word) != 0)
    {
        // Go to next node in the linked list
        cursor = cursor->next;
        // Return false if meet the end of the list
        if (cursor == NULL)
        {
            return false;
        }
    }
    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // djb2 algorithm
    unsigned long h = 5381;
    int c;
    while ((c = *word++))
    {
        c = tolower(c);
        h = (((h << 5) + h) + c) % N;   // hash * 33 + c
    }
    return h;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *raw_file = fopen(dictionary, "r");
    if (raw_file == NULL)
    {
        return false;
    }
    // Read string from file
    char *word = malloc(LENGTH + 1);
    if (word == NULL)
    {
        printf("Cannot generate memory for word.\n");
        return false;
    }
    int index;
    while (fscanf(raw_file, "%s", word) != EOF)
    {
        // Create a new node to store the read in word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Cannot generate memory for a new node.\n");
            return false;
        }
        strcpy(n->word, word);
        n->next = NULL;
        // Hash word to obtain a hash value
        index = hash(word);
        // Insert node into hash table
        n->next = table[index];
        table[index] = n;
        // Add 1 to the size counter
        size_count++;
    }
    fclose(raw_file);
    free(word);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // Returns the global variable size_count,
    // which has already counted while loading
    return size_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *cursor = NULL;
    // Free up memory list by list
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        // Free up memory one by one
        while (cursor != NULL)
        {
            // Store tmp to current node
            node *tmp = cursor;
            // Move cursor to next node before freeing up current node
            cursor = cursor->next;
            // Free up current node
            free(tmp);
        }
    }
    free(cursor);
    return true;
}
