#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    // count_letters(text);
    // count_words(text);
    // count_sentences(text);

    // L is the average number of letters per 100 words in the text,
    float L = ((float) count_letters(text) / count_words(text)) * 100;

    // S is the average number of sentences per 100 words in the text.
    float S = ((float) count_sentences(text) / count_words(text)) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);
    // printf("%i\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int numberOfLetters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            numberOfLetters++;
        }
    }

    // printf("%i letters\n", numberOfLetters);
    return numberOfLetters;
}

int count_words(string text)
{
    int numberOfWords = 1; // 1 accounts for the last word without a space at the end

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            numberOfWords++;
        }
    }
    // printf("%i words\n", numberOfWords);
    return numberOfWords;
}

/**
IMPORTANT
There is a distinction between 'a' and "a":

https://stackoverflow.com/questions/2603039/warning-comparison-with-string-literals-results-in-unspecified-behaviour
'a' means the value of the character a.
"a" means the address of the memory location where the string "a" is stored (which will generally be in the data section of your program's memory space).
At that memory location, you will have two bytes -- the character 'a' and the null terminator for the string.
*/

int count_sentences(string text)
{
    int numberOfSentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') // see note above rgd 'a' and "a"
        {
            numberOfSentences++;
        }
    }
    // printf("%i sentences\n", numberOfSentences);
    return numberOfSentences;
}