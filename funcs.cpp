#include <iostream>
#include "imageio.h"
#include "funcs.h"

/*
Task A:
Write a new program invert.cpp that inverts all colors, so white shades become black, and black become white:
*/
void invert(int image[MAX_H][MAX_W], int &h, int &w){
  int result[MAX_H][MAX_W];

    for (int row = 0; row < h; row++){
        for (int col = 0; col < w; col++){
            inverted_image[row][col] = 255 - image[row][col]; //to invert the colors
        }
    }
    writeImage("taskA.pgm", inverted_image, h, w); //creates designated file for output image

}


/*
Task B:
Write a program invert-half.cpp that inverts the colors only in the right half of the picture.
*/
void invert_half(int image[MAX_H][MAX_W], int &h, int &w){
  int half_invert_image[MAX_H][MAX_W];

  for(int row = 0; row < h; row++){
    for(int col = 0; col < w; col++){
      int widthHalf = w/2; //separates the non-inverted and inverted side; halves it

      if (widthHalf <= col){ 
        half_invert_image[row][col] = 255 - image[row][col]; //invert
      }
      else{
        half_invert_image[row][col] = image[row][col]; //keep the same colors
      }
    }
  }
  writeImage("taskB.pgm", half_invert_image, h, w);
  
}


/*
Task C:
Write a program box.cpp that draws a white box exactly in the middle of the picture. The dimensions of the box should be 50% by 50% of the original picture’s width and height.
*/
void box(int image[MAX_H][MAX_W], int &h, int &w){
  int image_with_box[MAX_H][MAX_W];

  for(int row = 0; row < h; row++){
    for(int col = 0; col < w; col++){
      if( (row > h/4) && (row < (h*3)/4) && (col > w/4) && (col < (w*3)/4) ){
        image_with_box[row][col] = 255; //convert to white
      }
    }
  }
  writeImage("taskC.pgm", image_with_box, h, w);

}


/*
Task D:
Program frame.cpp. Same as the previous task, but it should be a frame exactly one pixel thick.
*/
void frame(int image[MAX_H][MAX_W], int &h, int &w){
  int framed_image[MAX_H][MAX_W];
  int result[MAX_H][MAX_W];

  for(int row = 0; row < h; row++){
    for(int col = 0; col < w; col++){
      if( row >= (h/4) && row <= (h*3/4) && (col >= w/4) && (col <= (w*3)/4) &&  (row == h/4 || row == h*3/4 || col == w/4 || col == w*3/4) ){
        framed_image[row][col] = 255; //convert to white
      }
      else
      {
        framed_image[row][col] = image[row][col]; 
      }
    }
  }
  writeImage("taskD.pgm", framed_image, h, w);
        result[row][col] = 255; //convert to white
      }
      else
      {
        result[row][col] = image[row][col]; 
      }
    }
  }
  writeImage("taskD.pgm", result, h, w);
  
}


/*
Task E:
Program scale.cpp. Scale the original picture to 200% of its size. It can be done by increasing the size of the picture by the factor of 2, and copying each pixel of the input as a small 2x2 square in the output.
*/
void scale(int image[MAX_H][MAX_W], int &h, int &w){
  int scaled_image[MAX_H][MAX_W];

  for(int row = 0; row < h; row++){
    for(int col = 0; col < w; col++){
      scaled_image[row*2][col*2] = image[row][col];
      scaled_image[row*2+1][col*2] = image[row][col];
      scaled_image[row*2][col*2+1] = image[row][col];
      scaled_image[row*2+1][col*2+1] = image[row][col];
    }
  }
  writeImage("taskE.pgm", scaled_image, h*2, w*2);
  
}


/*
Task F:
Program pixelate.cpp will be pixelating the input image.
*/

/*
One way to pixelate an image is to effectively make every 2x2 non-overlapping window contain the same value (averaged over all the pixels in that window of the input). For example, the following image:
*/
void pixelate(int image[MAX_H][MAX_W], int &h, int &w){
  int pixeled_image[MAX_H][MAX_W];

  for(int row = 0; row < h; row+=2){ //2x2
    for(int col = 0; col < w; col+=2){ //2x2
      int sum = image[row][col] + image[row+1][col] + image[row][col+1] + image[row+1][col+1]; 
      int average = sum/4; //avg value of pixels

      pixeled_image[row][col] = average;
      pixeled_image[row+1][col] = average;
      pixeled_image[row][col+1] = average;
      pixeled_image[row+1][col+1] = average;
    }
  }
  writeImage("taskF.pgm", pixeled_image, h, w);
  
}
