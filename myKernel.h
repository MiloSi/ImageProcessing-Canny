#pragma once

#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

template <typename T>
inline T MULT(T value) {
	return value*value;
};
template <typename T>
inline T MULT(T value1, T value2)
{
	return (value1 * value1) + (value2 * value2);
};


enum ORIENTATION { VERTICAL = 1, HORIZONTAL = 2 };

Mat myGaussainKernel(const Size);
Mat mySobelKernel(ORIENTATION flag);
Mat myPrwittKernel(ORIENTATION flag);




uchar prwitt1[3][3] = {
	{ 1,1,1 },
	{ 0,0,0 },
	{ -1,-1,-1 }
};
uchar prwitt2[3][3] = {
	{ 1, 0,-1 },
	{ 1, 0,-1 },
	{ 1, 0,-1 }
};
uchar sobel1[3][3] = {
	{ 1,2,1 },
	{ 0,0,0 },
	{ -1,-2,-1 }
};
uchar sobel2[3][3] = {
	{ 1,0, -1 },
	{ 2,0, -2 },
	{ 1,0,-1 }
};