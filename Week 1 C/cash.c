/* A program that first asks the user how much change is owned and then
prints the minimum number of coins with which that change can be made. */

#include <stdio.h>
#include <cs50.h>
#include <math.h>   // for round function

float get_positive_float(string prompt);

int main(void)
{
    float dollars = get_positive_float("Change owned: ");

    // Round up to cents so no need to check
    // if user's input is too large to fit in a float
    int cents = round(dollars * 100);
    int a, b, c, d;

    // How many 25 cents?
    for (a = 0; cents >= 25; a++)
    {
        cents -= 25;
    }

    // How many 10 cents?
    for (b = 0; cents >= 10; b++)
    {
        cents -= 10;
    }

    // How many 5 cents?
    for (c = 0; cents >= 5; c++)
    {
        cents -= 5;
    }

    // How many 1 cents?
    for (d = 0; cents >= 1; d++)
    {
        cents -= 1;
    }
    printf("%i\n", a + b + c + d);
}

// Get a non-negative float from user
// Keep asking if user did not input the right number
float get_positive_float(string prompt)
{
    float n;
    do
    {
        n = get_float("%s", prompt);
    }
    while (n < 0);
    return n;
}
