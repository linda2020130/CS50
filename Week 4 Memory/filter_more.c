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
    // Run each pixel(i, j) and each one will become the average of pixel(K, l) based on the 3X3 grid of pixels
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy original image and add one row and one column to head and bottom respectively
    RGBTRIPLE original_image[height + 2][width + 2];
    for (int i = 0; i < height + 2; i++)
    {
        // First and last rows are set to 0
        if (i == 0 || i == height + 1)
        {
            for (int j = 0; j < width + 2; j++)
            {
                original_image[i][j].rgbtRed = 0;
                original_image[i][j].rgbtGreen = 0;
                original_image[i][j].rgbtBlue = 0;
            }
        }
        else
        {
            for (int j = 0; j < width + 2; j++)
            {
                // First and last columns are set to 0
                if (j == 0 || j == width + 1)
                {
                    original_image[i][j].rgbtRed = 0;
                    original_image[i][j].rgbtGreen = 0;
                    original_image[i][j].rgbtBlue = 0;
                }
                else
                {
                    original_image[i][j].rgbtRed = image[i - 1][j - 1].rgbtRed;
                    original_image[i][j].rgbtGreen = image[i - 1][j - 1].rgbtGreen;
                    original_image[i][j].rgbtBlue = image[i - 1][j - 1].rgbtBlue;
                }
            }
        }
    }
    // Run each pixel(i, j) and each one will become sqare root of (Gx^2 + Gy^2) based on 3X3 grid of pixels
    int sumGxRed, sumGyRed, sumGxGreen, sumGyGreen, sumGxBlue, sumGyBlue;
    int edgeRed, edgeGreen, edgeBlue;
    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < width + 1; j++)
        {
            // Calculate GxRed
            sumGxRed = original_image[i - 1][j - 1].rgbtRed * (-1) + original_image[i][j - 1].rgbtRed * (-2)
                       + original_image[i + 1][j - 1].rgbtRed * (-1) + original_image[i - 1][j + 1].rgbtRed
                       + original_image[i][j + 1].rgbtRed * 2 + original_image[i + 1][j + 1].rgbtRed;
            // Calculate GyRed
            sumGyRed = original_image[i - 1][j - 1].rgbtRed * (-1) + original_image[i - 1][j].rgbtRed * (-2)
                       + original_image[i - 1][j + 1].rgbtRed * (-1) + original_image[i + 1][j - 1].rgbtRed
                       + original_image[i + 1][j].rgbtRed * 2 + original_image[i + 1][j + 1].rgbtRed;
            // Combine GxRed and GyRed
            edgeRed = round(sqrtf((float)pow(sumGxRed, 2) + pow(sumGyRed, 2)));
            // Check if the combination is bigger than 255
            if (edgeRed < 255)
            {
                image[i - 1][j - 1].rgbtRed = edgeRed;
            }
            else
            {
                image[i - 1][j - 1].rgbtRed = 255;
            }
            // Calculate GxGreen
            sumGxGreen = original_image[i - 1][j - 1].rgbtGreen * (-1) + original_image[i][j - 1].rgbtGreen * (-2)
                         + original_image[i + 1][j - 1].rgbtGreen * (-1) + original_image[i - 1][j + 1].rgbtGreen
                         + original_image[i][j + 1].rgbtGreen * 2 + original_image[i + 1][j + 1].rgbtGreen;
            // Calculate GyGreen
            sumGyGreen = original_image[i - 1][j - 1].rgbtGreen * (-1) + original_image[i - 1][j].rgbtGreen * (-2)
                         + original_image[i - 1][j + 1].rgbtGreen * (-1) + original_image[i + 1][j - 1].rgbtGreen
                         + original_image[i + 1][j].rgbtGreen * 2 + original_image[i + 1][j + 1].rgbtGreen;
            // Combine GxGreen and GyGreen
            edgeGreen = round(sqrtf((float)pow(sumGxGreen, 2) + pow(sumGyGreen, 2)));
            // Check if the combination is bigger than 255
            if (edgeGreen < 255)
            {
                image[i - 1][j - 1].rgbtGreen = edgeGreen;
            }
            else
            {
                image[i - 1][j - 1].rgbtGreen = 255;
            }
            // Calculate GxBlue
            sumGxBlue = original_image[i - 1][j - 1].rgbtBlue * (-1) + original_image[i][j - 1].rgbtBlue * (-2)
                        + original_image[i + 1][j - 1].rgbtBlue * (-1) + original_image[i - 1][j + 1].rgbtBlue
                        + original_image[i][j + 1].rgbtBlue * 2 + original_image[i + 1][j + 1].rgbtBlue;
            // Calculate GyBlue
            sumGyBlue = original_image[i - 1][j - 1].rgbtBlue * (-1) + original_image[i - 1][j].rgbtBlue * (-2)
                        + original_image[i - 1][j + 1].rgbtBlue * (-1) + original_image[i + 1][j - 1].rgbtBlue
                        + original_image[i + 1][j].rgbtBlue * 2 + original_image[i + 1][j + 1].rgbtBlue;
            // Combine GxBlue and GyBlue
            edgeBlue = round(sqrtf((float)pow(sumGxBlue, 2) + pow(sumGyBlue, 2)));
            // Check if the combination is bigger than 255
            if (edgeBlue < 255)
            {
                image[i - 1][j - 1].rgbtBlue = edgeBlue;
            }
            else
            {
                image[i - 1][j - 1].rgbtBlue = 255;
            }
        }
    }
    return;
}
