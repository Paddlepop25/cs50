#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string key);
int rotate(char c, int key);

int main(int argc, string argv[])
{
// your program is executed without any command-line arguments or with more than one command-line argument
// print error message and return 1
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// any of the characters of the command-line argument is not a decimal digit
// print the message Usage: ./caesar key and return 1
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// print plaintext: (then string from user)
// print ciphertext: xx
// must preserve case
// print a newline

    int key = atoi(argv[1]);
    string user_text = get_string("plain text:  ");
    printf("ciphertext: ");

    for (int i = 0, len = strlen(user_text); i < len; i++)
    {
        printf("%c", rotate(user_text[i], key));
    }
    printf("\n");
    return 0;
}

bool only_digits(string key)
{
// check input only contains digits
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

int rotate(char c, int key)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            return ((c - 65 + key) % 26) + 65;
        }
        else
        {
            return ((c - 97 + key) % 26) + 97; // 26 because 26 letters in alphabets
        }
    }
    else
    {
        return c;
    }
}