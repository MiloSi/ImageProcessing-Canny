#pragma once
#pragma warning(disable : 4996)
#include <opencv2\opencv.hpp>


using namespace cv;


enum FILTERING {
	BLUR = 1,
	DERIVATIVE,
};

double calculation1(const Mat kernel, Mat pixels);
double calculation2(const Mat kernel, Mat pixels);
Mat myConvolution(const Mat src, Mat& kernel, FILTERING flag);


