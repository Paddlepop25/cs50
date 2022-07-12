#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // initialize variable
    long creditCard;
    int digit;
    int position = 0;
    long firstTwoDigits;

    int first_digit;
    int second_digit;
    int sumOfEveryOther2nd = 0;
    int sumOfEveryOtherDigits = 0;
    int sumOfAllDigits = 0;

    // ask user for input
    do
    {
        creditCard = get_long("Enter a credit card number: ");
    }
    while (creditCard <= 0);

    // get first 2 digits of credit card
    firstTwoDigits = creditCard;
    do
    {
        firstTwoDigits = firstTwoDigits / 10;
    }
    while (firstTwoDigits > 100);

    // validate checksum
    while (creditCard > 0)
    {
      digit = creditCard % 10; // get last digit
      creditCard /= 10; // get remaining credit card numbers
      position++; // iterate through each position of credit card number

    // for even positions
    if (position % 2 == 0)
    {
        digit *= 2;
        first_digit = digit / 10;
        second_digit = digit % 10;

        sumOfEveryOther2nd += first_digit;
        sumOfEveryOther2nd += second_digit;
    }
    // for odd positions
    if (position % 2 != 0)
    {
        sumOfEveryOtherDigits += digit;
    }
    }

    // check if credit card is valid or invalid
    sumOfAllDigits = sumOfEveryOther2nd + sumOfEveryOtherDigits;
    if (sumOfAllDigits % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // check if credit card is valid or invalid based on length
    if (position != 13 && position != 15 && position != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // check what type of credit card if valid
    if ((firstTwoDigits / 10 == 5) && (0 < firstTwoDigits % 10 && firstTwoDigits % 10 < 6))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else if ((firstTwoDigits / 10 == 3) && (firstTwoDigits % 10 == 4 || firstTwoDigits % 10 == 7))
    {
        printf("AMEX\n");
        return 0;
    }
    else if (firstTwoDigits / 10 == 4)
    {
        printf("VISA\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}