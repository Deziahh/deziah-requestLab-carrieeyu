#include <iostream>
#include "imageio.h"
#include "funcs.h"

//task A

/*
Write a new program invert.cpp that inverts all colors, so white shades become black, and black become white:

Since black = 0, and white = 255, you should do the following transformation for each pixel color:

0 → 255
1 → 254
2 → 253
…
254 → 1
255 → 0
*/

void invert(int image[MAX_H][MAX_W], int &height, int &width){

    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            image[row][col] = 255 - image[row][col];
        }
    }
    writeImage("invertFile.pgm", image, height, width);

}