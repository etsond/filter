#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //go through each row
    for (int i = 0; i < height; i++)
    {
        //go through column
        for (int j = 0; j < width; j++)
        {
            //roundng the pixels number
            float Blue = image[i][j].rgbtBlue;
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;


            //Get the average of the RGBT value to see the value
            int average = round((Red + Green + Blue) / 3);
            //setting the rgbt for Red, blue, green to equal to the average
            image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //apply algorithm to each pixel to get new rgb value
    //round the result
    //cap value at 255 if it is bigger than 255
    // go through row

    for (int i = 0; i < height; i++)
    {
        //go through the row
        for (int j = 0; j < width; j++)
        {
            //make another pixel to float
            float originalBlue = image[i][j].rgbtBlue;
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;

            //red Serpia filter
            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            //green serpia filter
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            //Blue serpia filter
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            //if it is bigger than 255 we capped it
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //get the new pixels after it has been capped at 255
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
    //go to each row
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            //packing the image
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //copy the picture
    RGBTRIPLE tmp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //copying the pixels to the original image
            tmp[i][j] = image[i][j];
        }
    }
    //looping through image by going though every single pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;

            //getting  pixelated image
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int nowX = i + x;
                    int nowY = j + y;

                    //isvalid
                    if (nowX < 0 || nowX > (height - 1) || nowY < 0 || nowY > (width - 1))
                    {
                        //if its not valid it will skip and continue
                        continue;
                    }
                    //add the value
                    totalRed += image[nowX][nowY].rgbtRed;
                    totalGreen += image[nowX][nowY].rgbtBlue;
                    totalBlue += image[nowX][nowY].rgbtGreen;
                    counter++;
                }
                //calculate the nex pixel value
                tmp[i][j].rgbtRed = round(totalRed / counter);
                tmp[i][j].rgbtGreen = round(totalGreen / counter);
                tmp[i][j].rgbtBlue = round(totalBlue / counter);

            }
        }
    }
    //update pixels to unfilter image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //copying the value
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
        }
    }
    return;
}
