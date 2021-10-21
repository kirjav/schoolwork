#include <stdio.h>
#include <stdlib.h>
#include "MyroC.h"
#include <string.h>
#include <math.h>


/* C code programming exercises on color and picture display */

void pixelStrip (Picture * pic, char color);
void pictureRedder (Picture * pic);
void pictureGreener(Picture * pic);
void pictureBluer (Picture * pic);
void circleSelect (Picture * pic, int xCenter, int yCenter, int Radius);
void Greyscale(Picture * pic)
void popArt (Picture * pic);
Picture createimage (int height, int width);


int main() {
    int xCenter = 100;
    int yCenter = 150;
    int Radius = 40;
    char color;
    Picture pic = createimage (200,300);

    printf("Please input your desired primary color (R/G/B): ")
    scanf("%c", &color);

    /* Test functions - uncomment to test
    pixelStrip(&pic, color);
    pictureRedder(&pic);
    pictureBluer(&pic);
    pictureGreener(&pic);
    circleSelect(&pic, xCenter, yCenter, Radius); */

    rDisplayPicture (&pic, 10, "display of pic");

    return 0;
}

/*A function that allows us to create a simply one-value image,
through which we can do testing. We have certain colors predefined (red, blue, green, black)
and are able to put in whatever color we want, if we want to test our program.
It currently makes a red image*/
Picture createimage (int height, int width) {
    int i, j;
    Picture newP;
    Pixel blackPix = {0, 0, 0};
    Pixel red = {255, 0, 0};
    Pixel blue = {0, 0, 255};
    Pixel green = {0,255,0};

    newP.width = width;
    newP.height = height;

    /* iterate through all pixels in the picture, setting each to black */
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            newP.pix_array[i][j] = red;
          }
        }
    return newP;
}

void pixelStrip (Picture * pic, char color) {

    int row, col;

    if (color == 'R' || color == 'r') {

        for (row = 0; row < (*pic).height; row++)
        {
            for (col = 0; col < (*pic).width; col++)
            {

                (*pic).pix_array[row][col].R = 0;
            }
        }
    }


    if (color == 'G' || color == 'g') {
        //sets G to 0
        for (row = 0; row < (*pic).height; row++)
        {
            for (col = 0; col < (*pic).width; col++)
            {
                (*pic).pix_array[row][col].G = 0;
            }
        }
     }

    if (color == 'B' || color == 'b') {
       //sets B to 0
        for (row = 0; row < (*pic).height; row++)
        {
            for (col = 0; col < (*pic).width; col++)
            {
                (*pic).pix_array[row][col].B = 0;
            }
    }
}
}

void pictureRedder (Picture * pic) {
    int increase = 20;
    int row, col;

    for (row = 0; row < (*pic).height; row++)
    {
        for (col = 0; col < (*pic).width; col++)
        {
            if (((*pic).pix_array[row][col].R + increase) < (255-increase)) {
                (*pic).pix_array[row][col].R = (*pic).pix_array[row][col].R + increase;
            }
        }
}
}

void pictureGreener(Picture * pic) {
    int increase = 20;
    int row, col;

    for (row = 0; row < (*pic).height; row++)
    {
        for (col = 0; col < (*pic).width; col++)
        {
            if (((*pic).pix_array[row][col].G + increase) < (255-increase)) {
            (*pic).pix_array[row][col].G = (*pic).pix_array[row][col].G + increase;
        }
        }
    }
}

void pictureBluer (Picture * pic) {
    int increase = 20;
    int row, col;

    for (row = 0; row < (*pic).height; row++)
    {
        for (col = 0; col < (*pic).width; col++)
        {
            if (((*pic).pix_array[row][col].B + increase) < (255-increase)) {
                (*pic).pix_array[row][col].B = (*pic).pix_array[row][col].B + increase;
            }
        }
    }
}

/*This function selects a circle at location (xCenter,yCenter) with a radius of Radius
and transforms every respective value inside of it to greyscale.
The greyscale conversion used is:
30% of the Red value
59% of the green value
11% of the blue value */
void circleSelect (Picture * pic, int xCenter, int yCenter, int Radius) {
    int row, col;
    int greyscale;
    float distance;

    for (row = (xCenter - Radius); row < (xCenter+Radius); row++)
    {
        for (col = (yCenter-Radius); col < (yCenter+Radius); col++)
        {
            int x = (yCenter-col);
            int y = (xCenter-row);
            distance = sqrt((x*x)+(y*y));

            if (distance <= Radius){
            greyscale = ((((*pic).pix_array[row][col].R)/3) + (()(*pic).pix_array[row][col].G)/5.9) + (()(*pic).pix_array[row][col].B)/1.1));
            (*pic).pix_array[row][col].R = greyscale;
            (*pic).pix_array[row][col].G = greyscale;
            (*pic).pix_array[row][col].B = greyscale;
            }
        }
    }
}
/*Creates a "popArt" piece of the image. shift the hue of the image by a certain % 3
 times and make a collage of it.
 Other options are have 4 different colored pictures attached to each other.
 Quetions: Call functions in here? or should i make multiple versions of pictures in (main)
 that will function as the 4 different pictures here. Mmm
 */
void popArt (Picture * pic) {
Picture newP;
Picture picR;
Picture picB;
Picture picG;
Picture picGrey;
int i, j;



newP.height = ((*pic).height)*2;
newP.width =  ((*pic).width)*2;
// For every picture one starts at 0,0, the other at. (newP.height / 2)& newP.width/2
// the other at 0 & newPheight/2. . And the fourth at newpwidth/2 & 0.
for (i = 0; i < height; i++) {
  for (j = 0; j < width; j++) {
    newP.pix_array[i][j] = red;
    }
  }
return newP;
}

void Greyscale(Picture * pic) {
  int row, col;
  int greyscale;

  for (row = 0; row < (*pic).height; row++)
  {
      for (col = 0; col < (*pic).width; col++)
      {
          greyscale = ((((*pic).pix_array[row][col].R)/3) + (()(*pic).pix_array[row][col].G)/5.9) + (()(*pic).pix_array[row][col].B)/1.1));
          (*pic).pix_array[row][col].R = greyscale;
          (*pic).pix_array[row][col].G = greyscale;
          (*pic).pix_array[row][col].B = greyscale;
          }
      }
}
