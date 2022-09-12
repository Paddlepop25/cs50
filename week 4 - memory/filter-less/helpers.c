#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;

    // loop through each row
    for (int i = 0; i < height; i++)
    {
        // loop through each pixel
        for (int j = 0; j < width; j++)
        {
            // get rgb values
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // get average rgb value, round to nearest int
            average = round(((float)red + (float)green + (float)blue) / 3);

            // set to grayscale
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;

    // get rgb values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // get sepia colours
            int convertedRed = round((0.393 * red) + (0.769 * green) + (0.189 * blue));
            int convertedGreen = round((0.349 * red) + (0.686 * green) + (0.168 * blue));
            int convertedBlue = round((0.272 * red) + (0.534 * green) + (0.131 * blue));

            // maximum R,G,B should be 255 if it's above 255
            if (convertedRed > 255)
            {
                sepiaRed = 255;
            }
            else if (convertedRed <= 255)
            {
                sepiaRed = convertedRed;
            }

            if (convertedGreen > 255)
            {
                sepiaGreen = 255;
            }
            else if (convertedGreen <= 255)
            {
                sepiaGreen = convertedGreen;
            }

            if (convertedBlue > 255)
            {
                sepiaBlue = 255;
            }
            else if (convertedBlue <= 255)
            {
                sepiaBlue = convertedBlue;
            }

            // set to sepia
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // loop through each row
    for (int i = 0; i < height; i++)
    {
        // iterate through array till mid point only
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp = image[i][j];

            // swap pixels
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // make temp image to implement blurred algorithm on it
    RGBTRIPLE newimage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int total_red, total_blue, total_green;
            total_red = total_blue = total_green = 0;
            float counter = 0.00;

            // check surrounding pixels (from center pixel perspective in 3x3 box)
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    // check if neighbouring pixels is within bounds
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    // add r,g,b values to get total values
                    total_red += image[currentX][currentY].rgbtRed;
                    total_green += image[currentX][currentY].rgbtGreen;
                    total_blue += image[currentX][currentY].rgbtBlue;
                    counter++;
                }

                // get average values of neighbouring pixels
                newimage[i][j].rgbtRed = round(total_red / counter);
                newimage[i][j].rgbtGreen = round(total_green / counter);
                newimage[i][j].rgbtBlue = round(total_blue / counter);
            }
        }
    }
    // copy blurred image to original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = newimage[i][j].rgbtRed;
            image[i][j].rgbtGreen = newimage[i][j].rgbtGreen;
            image[i][j].rgbtBlue = newimage[i][j].rgbtBlue;
        }
    }
    return;
}
