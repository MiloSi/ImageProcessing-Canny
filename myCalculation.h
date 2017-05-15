#pragma once
#pragma warning (disable : 4996)
#include <cmath>
#include <opencv2\opencv.hpp>

using namespace cv;


enum OPERATION{
	MAGNITUDE = 1,
	DIRECTION = 2
};



Mat myMatrixOperation(Mat&, Mat&, OPERATION flag);
Mat myTraceEdge(Mat&, Mat&, double, double);