#include <iostream>
#include "imageio.h"
#include "funcs.h"

int main() {
  //variables
  int image[MAX_H][MAX_W];
  int height;
  int width;
  
  readImage("inImage.pgm", image, height, width);
  
  //task A
  //std:: cout << "t" << std:: endl;
  invert(image, height, width);
}