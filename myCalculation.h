#pragma once
#pragma warning (disable : 4996)
#include <cmath>
#include <opencv2\opencv.hpp>

using namespace cv;


enum OPERATION{
	MAGNITUDE = 1,
	DIRECTION = 2
};



Mat myMatrixOperation(Mat&, Mat&, OPERATION flag = MAGNITUDE);
Mat myMatrixOperation(Mat& mat1, Mat& mat2, const Mat magnitude, OPERATION flag = DIRECTION);
Mat myTraceEdge(Mat&, Mat&, const double, const double);
void myRemoveWeakEdge(Mat&);