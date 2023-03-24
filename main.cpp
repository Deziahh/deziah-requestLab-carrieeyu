#include <iostream>
#include "imageio.h"
#include "funcs.h"

int main() {
  //variables
  int image[MAX_H][MAX_W];
  int h;
  int w;

  //example image that's being modified by functions A-F
  readImage("inImage.pgm", image, h, w);
  
  //task A
  invert(image, h, w);

  //task B
  invert_half(image, h, w);

  //task C
  box(image, h, w);

  //task D
  frame(image, h, w);
  
  //task E
  scale(image, h, w);

  //task F
  pixelate(image, h, w);
}
