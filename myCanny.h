#pragma once
#pragma warning(disable : 4996)
#include <opencv2\opencv.hpp>
#include "myConvolution.h"
#include "myKernel.h"

using namespace cv;


void myCannyEdge(Mat src, Mat& dst);