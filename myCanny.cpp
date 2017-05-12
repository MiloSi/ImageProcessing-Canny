#pragma once
#include "myCanny.h"


void myCannyEdge(Mat src, Mat& dst)
{

	if (src.type() != CV_8UC1)
		cvtColor(dst, dst, CV_BGR2GRAY);


	/// GAUSSIAN FILTER
	dst = myConvolution(dst, myGaussianKernel(), BLUR);


	Mat sobel1 = myConvolution(dst, mySobelKernel(), DERIVATIVE);
	Mat sobel2 = myConvolution(dst, mySobelKernel(HORIZONTAL), DERIVATIVE);

	

}