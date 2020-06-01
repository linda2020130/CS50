// Implement Luhn's Algorithm to check if a credit crad is valid

#include <stdio.h>
#include <cs50.h>
#include <string.h>

long get_positive_long(string prompt);
int get_digit(long n);

int main(void)
{
    long credit = get_positive_long("Number: ");
    int N = get_digit(credit);  
    
    // Generate an array of credit card numbers (integers)
    // the last credit number is the first integer in the array
    int digit_arr[N];
    for (int i = 0; i < N; i++)
    {
        digit_arr[i] = credit % 10;
        credit = (credit - digit_arr[i]) / 10;
    }
    
    // sum_odd is sum of odd digits in credit card number (even position in the array)
    int sum_odd = 0;
    for (int i = 0; i < N; i += 2)
    {
        sum_odd += digit_arr[i];
    }

    // sum_even is sum of (2 * even digits) in credit card number (odd position in the array)
    int sum_even = 0;
    for (int i = 1; i < N; i += 2)
    {
        if (digit_arr[i] < 5)   // Only 1-digit
        {
            sum_even += 2 * digit_arr[i];
        }
        else  // 2-digit needs to be split and add up (e.g. 12 => 1 + 2)
        {
            sum_even += 1 + (2 * digit_arr[i]) % 10;
        }
    }

    // Check if credit card is valid
    if ((sum_odd + sum_even) % 10 == 0)
    {
        // Check if number is American Express
        // Length is 15 and start with 34 or 37
        if (N == 15 && digit_arr[14] == 3)
        {
            if (digit_arr[13] == 4 || digit_arr[13] == 7)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // Check if number is Visa
        // Length is 13 or 16 and start with 4
        else if (N == 16 && digit_arr[15] == 4)
        {
            printf("VISA\n");
        }
        else if (N == 13 && digit_arr[12] == 4)
        {
            printf("VISA\n");
        }
        // Check if number is MasterCard
        // Length is 16 and start with 51, 52, 53, 54, or 55
        else if (N == 16 && digit_arr[15] == 5)
        {
            if (digit_arr[14] == 1 || digit_arr[14] == 2 || digit_arr[14] == 3 || digit_arr[14] == 4 || digit_arr[14] == 5)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}


// Get a non-negative long from user
// Keep asking if user did not input the right number
long get_positive_long(string prompt)
{
    long n;
    do
    {
        n = get_long("%s", prompt);
    }
    while (n < 0);
    return n;
}

// How many digit does the long number have?
int get_digit(long n)
{
    int count = 0;
    
    do
    {
        n /= 10;
        count ++;
    }
    while (n != 0);
    return count;
}
