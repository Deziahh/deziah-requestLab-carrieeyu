#pragma once
#include <iostream>
#include "imageio.h"

//task A
void invert(int image[MAX_H][MAX_W], int &h, int &w);

//task B
void invert_half(int image[MAX_H][MAX_W], int &h, int &w);

//task C
void box(int image[MAX_H][MAX_W], int &h, int &w);

//task D
void frame(int image[MAX_H][MAX_W], int &h, int &w);

//task E
void scale(int image[MAX_H][MAX_W], int &h, int &w);

//task F
void pixelate(int image[MAX_H][MAX_W], int &h, int &w);
