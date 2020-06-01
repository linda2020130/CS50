// A program that computes the approximate reading levels by Coleman-Liau index

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string text, int length);
int count_words(string text, int length);
int count_sentences(string text, int length);
int get_index(int letter, int word, int sentence);

int main(void)
{
    // Get some text input from the user
    string text = get_string("Text: ");
    int length = strlen(text);
    
    // Get letter counts from given text
    int letter = count_letters(text, length);
    //printf("%i letter(s)\n", letter);
    
    // Get word counts from given text
    int word = count_words(text, length);
    //printf("%i word(s)\n", word);
    
    // Get sentence count from given text
    int sentence = count_sentences(text, length);
    //printf("%i sentence(s)\n", sentence);
    
    int index = get_index(letter, word, sentence);
    // Output "Grade 16+" if index >= 16
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    // Output "Before Grade 1" if index < 1
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    
}

// Count letters from given text
// Only a-z or A-Z are considered as a letter
int count_letters(string text, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            count++;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            count++;
        }
    }
    return count;
}

// Count words from given text
// Only consider characters separated by a space to be a word
int count_words(string text, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

// Count sentences from given text
// Only consider characters that ends with '.' or '!' or '?' to be a sentence
int count_sentences(string text, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

// Calculate Coleman-Liau index
// Output reading level as round up of index
int get_index(int letter, int word, int sentence)
{
    float L = 100 * ((float)letter / word);
    float S = 100 * ((float)sentence / word);
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}
