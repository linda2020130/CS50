#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int ave;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Need to use 3.0 so that we can get decimal digits before going to round function
            ave = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = ave;
            image[i][j].rgbtGreen = ave;
            image[i][j].rgbtRed = ave;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalGreen, originalBlue;
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;
            // Convert rgbtRed
            sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            // Convert rgbtGreen
            sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            // Convert rgbtBlue
            sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int n = floor(width / 2);
    int tempRed, tempGreen, tempBlue;
    for (int i = 0; i < height; i++)
    {
        // Only need to run to middle of width
        for (int j = 0; j < n; j++)
        {
            // Save temp before assign to reflected one
            tempRed = image[i][j].rgbtRed;
            tempGreen = image[i][j].rgbtGreen;
            tempBlue = image[i][j].rgbtBlue;
            // Update left to right
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            // Update right to left
            image[i][width - 1 - j].rgbtRed = tempRed;
            image[i][width - 1 - j].rgbtGreen = tempGreen;
            image[i][width - 1 - j].rgbtBlue = tempBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy original image
    RGBTRIPLE original_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original_image[i][j].rgbtRed = image[i][j].rgbtRed;
            original_image[i][j].rgbtGreen = image[i][j].rgbtGreen;
            original_image[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    // Run each pixel(i, j) and each one will become the average of pixel(K, l)
    int count, sumRed, sumGreen, sumBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            count = 0;
            sumRed = 0;
            sumGreen = 0;
            sumBlue = 0;
            // Middle row(s)
            if (i > 0 && i < height - 1)
            {
                for (int k = i - 1; k < i + 2; k++)
                {
                    // Middle column(s)
                    if (j > 0 && j < width - 1)
                    {
                        for (int l = j - 1; l < j + 2; l++)
                        {
                            sumRed += original_image[k][l].rgbtRed;
                            sumGreen += original_image[k][l].rgbtGreen;
                            sumBlue += original_image[k][l].rgbtBlue;
                            count++;
                        }
                    }
                    // First column
                    else if (j == 0)
                    {
                        for (int l = 0; l < 2; l++)
                        {
                            sumRed += original_image[k][l].rgbtRed;
                            sumGreen += original_image[k][l].rgbtGreen;
                            sumBlue += original_image[k][l].rgbtBlue;
                            count++;
                        }
                    }
                    // Last column
                    else
                    {
                        for (int l = j - 1; l < width; l++)
                        {
                            sumRed += original_image[k][l].rgbtRed;
                            sumGreen += original_image[k][l].rgbtGreen;
                            sumBlue += original_image[k][l].rgbtBlue;
                            count++;
                        }
                    }
                }
            }
            // First row
            else if (i == 0)
            {
                for (int k = 0; k < 2; k++)
                {
                    // Middle column(s)
                    if (j > 0 && j < width - 1)
                    {
                        for (int l = j - 1; l < j + 2; l++)
                        {
                            sumRed += original_image[k][l].rgbtRed;
                            sumGreen += original_image[k][l].rgbtGreen;
                            sumBlue += original_image[k][l].rgbtBlue;
                            count++;
                        }
                    }
                    // First column
                    else if (j == 0)
                    {
                        for (int l = 0; l < 2; l++)
                        {
                            sumRed += original_image[k][l].rgbtRed;
                            sumGreen += original_image[k][l].rgbtGreen;
                            sumBlue += original_image[k][l].rgbtBlue;
                            count++;
                        }
                    }
                    // Last column
                    else
                    {
                        for (int l = j - 1; l < width; l++)
                        {
                            sumRed += original_image[k][l].rgbtRed;
                            sumGreen += original_image[k][l].rgbtGreen;
                            sumBlue += original_image[k][l].rgbtBlue;
                            count++;
                        }
                    }
                }
            }
            // Last row
            else
            {
                for (int k = i - 1; k < height; k++)
                {
                    // Middle column(s)
                    if (j > 0 && j < width - 1)
                    {
                        for (int l = j - 1; l < j + 2; l++)
                        {
                            sumRed += original_image[k][l].rgbtRed;
                            sumGreen += original_image[k][l].rgbtGreen;
                            sumBlue += original_image[k][l].rgbtBlue;
                            count++;
                        }
                    }
                    // First column
                    else if (j == 0)
                    {
                        for (int l = 0; l < 2; l++)
                        {
                            sumRed += original_image[k][l].rgbtRed;
                            sumGreen += original_image[k][l].rgbtGreen;
                            sumBlue += original_image[k][l].rgbtBlue;
                            count++;
                        }
                    }
                    // Last column
                    else
                    {
                        for (int l = j - 1; l < width; l++)
                        {
                            sumRed += original_image[k][l].rgbtRed;
                            sumGreen += original_image[k][l].rgbtGreen;
                            sumBlue += original_image[k][l].rgbtBlue;
                            count++;
                        }
                    }
                }
            }
            // Update blur pixel
            // Need to use float to get decimal digits before going to round function
            image[i][j].rgbtRed = round((float)sumRed / count);
            image[i][j].rgbtGreen = round((float)sumGreen / count);
            image[i][j].rgbtBlue = round((float)sumBlue / count);
        }
    }
    return;
}
