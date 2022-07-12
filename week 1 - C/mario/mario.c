#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask user for height (must be 1 - 8)
    int height;
    do
    {
        height = get_int("Enter the height of steps: ");
    }
    while (height < 1 || height > 8);

    // display column of input with 2 spaces in between
    for (int row = 0; row < height; row++)
    {
        for (int space = height - row - 1; space > 0; space--)
        {
            printf(" ");
        }
        for (int star = 0; star < row + 1; star++)
        {
            printf("#");
        }
        printf("  ");
        for (int star2 = 0; star2 < row + 1; star2++)
        {
            printf("#");
        }
        printf("\n"); //next line
    }
}

