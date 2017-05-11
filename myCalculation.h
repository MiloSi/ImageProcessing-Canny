#pragma once
#include <opencv2\opencv.hpp>

using namespace cv;

uchar calculation(Mat kernel, Mat pixel);



enum CALCULATING 
{
	FLOAT = 0,
	INTEGER = 1
};