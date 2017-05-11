#pragma once
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


template <typename T>
inline T MULT(T value);
template <typename T>
inline T MULT(T value1, T value2);

uchar calculation(Mat kernel, Mat pixel);
Mat gaussianFilter(const Mat src, const Size nSize, const double sigma);