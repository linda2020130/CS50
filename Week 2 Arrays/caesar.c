/*
Caesar used to encrypt confidential messages by shifting each letter therein by some number of places(called key).
So, make the user to run the program and also type in a key in the command-line argument.
Secondly, ask the user to type in plaintext(text that would like to encrpyt).
Finally, program should output the encrpted text(called ciphertext).
Note that only alphabet will be rotated. Other character will remain the same.
*/

#include <stdio.h>    // for printf function
#include <cs50.h>     // for get_string function
#include <string.h>   // for strlen function
#include <ctype.h>    // for isdigit function
#include <stdlib.h>   // for atoi function

int main(int argc, string argv[])
{
    // Check if user type in exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the only one argument contains only decimal digit
    int n = strlen(argv[1]);
    for (int i = 0; i < n; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Covert string argument to int key
    int key = atoi(argv[1]);

    // Get plaintext from user
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");

    // Convert plaintext into ciphertext
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++)
    {
        // Check if character is between A-Z
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            printf("%c", 65 + (plaintext[i] - 65 + key) % 26);
        }
        // Check if character is between a-z
        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            printf("%c", 97 + (plaintext[i] - 97 + key) % 26);
        }
        // Do not rotate if character is not alphabet
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
