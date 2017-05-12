#pragma once
#pragma warning(disable : 4996)

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

Mat myGaussianKernel(const Size nSize = Size(5, 5), const float sigma = 1.4);
Mat mySobelKernel(ORIENTATION flag = VERTICAL);
Mat myPrwittKernel(ORIENTATION flag = VERTICAL);


