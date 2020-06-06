/*
A program that can encrypt confidential messages by replacing every letter with another letter
according to the mapping key.
A correct key is a 26-character string with exactly A-Z alphabet appear once(no matter case).
First, make the user to run the program and also type in a key in the command-line argument.
Then, check if the type-in argument is exactly one and the key is valid.
Thirdly, ask the user to type in plaintext(text that would like to encrypt).
Finally, program should output the encrypted text(called ciphertext).
*/

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int check_alpha_unique(string key);
string plain_to_cipher(string key, string plaintext);

int main(int argc, string argv[])
{
    // Check if user input exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int length = strlen(argv[1]);
    // Check if key contains exactly 26 characters
    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        // Check if each key element is unique and is an alphabet
        if (check_alpha_unique(argv[1]) == 0)
        {
            printf("Key contains at least one non-alphabetic character or contains same alphabetic.\n");
            return 1;
        }
        else
        {
            string plaintext = get_string("plaintext:  ");
            string ciphertext = plain_to_cipher(argv[1], plaintext);
            printf("ciphertext: %s\n", ciphertext);
            return 0;
        }
    }
}

// Check if the key contains no non-alphatical characters
// And also check all alphatical characters appear exactly once
int check_alpha_unique(string key)
{
    // Generate an array of 26 zeros
    int checklist[26];
    int index;
    int multiple = 1;
    for (int i = 0; i < 26; i++)
    {
        checklist[i] = 0;
    }
    
    for (int i = 0; i < 26; i++)
    {
        // Check if the key element is alphabetical
        if (isalpha(key[i]) == 0)
        {
            return 0;
        }
        // Overwrite the checklist element
        // If all elements in the checklist can be overwritten, then each key element is unique
        else
        {
            index = toupper(key[i]) - 65;
            checklist[index] = key[i];
        }
    }

    // Check if all elements in the checklist have been overwritten
    // Equivalently, no element is still 0
    for (int i = 0; i < 26; i++)
    {
        multiple *= checklist[i];
        if (multiple == 0)
        {
            return 0;
        }
        else;
        {
            multiple = 1;
        }
    }
    return 1;
}

// Convert plaintext to ciphertext
string plain_to_cipher(string key, string plaintext)
{
    int length = strlen(plaintext);
    // Character keeps unchanged if it is a non-alphabetical character
    string ciphertext = plaintext;
    int index;
    for (int i = 0; i < length; i++)
    {
        // Uppercase keeps uppercase
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            index = plaintext[i] - 65;
            ciphertext[i] = toupper(key[index]);
        }
        // Lowercase keeps lowercase
        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            index = plaintext[i] - 97;
            ciphertext[i] = tolower(key[index]);
        }
    }
    return ciphertext;
}
