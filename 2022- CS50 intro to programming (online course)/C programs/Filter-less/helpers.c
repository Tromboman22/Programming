#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            avg = roundf(avg);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE r = roundf(image[i][j].rgbtRed);
            BYTE g = roundf(image[i][j].rgbtGreen);
            BYTE b = roundf(image[i][j].rgbtBlue);
            int rc = 0;
            int rg = 0;
            int rb = 0;

            if (round(0.393 * r + 0.769 * g + 0.189 * b) > 255)
            {
                image[i][j].rgbtRed = 255;
                rc = 1;
            }
            if (round(0.349 * r + 0.686 * g + 0.168 * b) > 255)
            {
                image[i][j].rgbtGreen = 255;
                rg = 1;
            }
            if (round(0.272 * r + 0.534 * g + 0.131 * b) > 255)
            {
                image[i][j].rgbtBlue = 255;
                rb = 1;
            }
            if (rc == 0)
            {
                image[i][j].rgbtRed = round(0.393 * r + 0.769 * g + 0.189 * b);
            }

            if (rg == 0)
            {
                image[i][j].rgbtGreen = round(0.349 * r + 0.686 * g + 0.168 * b);
            }
            if (rb == 0)
            {
                image[i][j].rgbtBlue = round(0.272 * r + 0.534 * g + 0.131 * b);
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        float r[width];
        float g[width];
        float b[width];
        for (int j = 0; j < width; j++)
        {
            r[j] = image[i][j].rgbtRed;
            g[j] = image[i][j].rgbtGreen;
            b[j] = image[i][j].rgbtBlue;
        }
        for (int k = 0; k < width; k++)
        {
            image[i][k].rgbtRed = r[width - (k + 1)];
            image[i][k].rgbtGreen = g[width - (k + 1)];
            image[i][k].rgbtBlue = b[width - (k + 1)];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float div = 0.0;
            int r = 0;
            int g = 0;
            int b = 0;

            for (int m = 0; m < 3; m++)
            {
                for (int n = 0; n < 3; n++)
                {
                    // If the value exists
                    if (0 < (i + m) && (i + m) < (height + 1))
                    {
                        if (0 < (j + n) && (j + n) < (width + 1))
                        {
                            // Use this pixel
                            r += image[i + m - 1][j + n - 1].rgbtRed;
                            g += image[i + m - 1][j + n - 1].rgbtGreen;
                            b += image[i + m - 1][j + n - 1].rgbtBlue;
                            div++;
                        }
                    }
                }
            }
            copy[i][j].rgbtRed = round(r / div);
            copy[i][j].rgbtGreen = round(g / div);
            copy[i][j].rgbtBlue = round(b / div);
        }
    }
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l] = copy[k][l];
        }
    }
    return;
}
