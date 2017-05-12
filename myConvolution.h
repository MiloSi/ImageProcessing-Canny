#pragma once
#pragma warning(disable : 4996)
#include <opencv2\opencv.hpp>


using namespace cv;


enum FILTERING {
	BLUR = 1,
	DERIVATIVE = 2
};

uchar calculation1(const Mat kernel, Mat pixels);
uchar calculation2(const Mat kernel, Mat pixels);
Mat myConvolution(const Mat src, const Mat kernel, FILTERING flag);


