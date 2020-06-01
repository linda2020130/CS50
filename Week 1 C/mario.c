//Use hashes to create pyramids in C and let user decide how tall the pyramids should be

#include <stdio.h>
#include <cs50.h>

int get_positive_int(string prompt);

int main(void)
{
    // Get positive integer from user
    int n = get_positive_int("Height: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n + 2; j++)
        {
            // left-side pyramid
            if (i + j > n - 2 && j < n)
            {
                printf("#");
            }
            // right-side pyramid
            else if (j > n + 1 && j - i < n + 3)
            {
                printf("#");
            }
            // space for all other positions
            else if (i + j < n - 1 || j == n || j == n + 1)
            {
                printf(" ");
            }
        }
        // change line at the bottom
        printf("\n");
    }
}

// Get a positive integer from user
// Keep asking if user did not input the right number
int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}
