#pragma once
#include "myCanny.h"
#include "myCalculation.h"


void myCannyEdge(Mat src, Mat& dst)
{

	if (src.type() != CV_8UC1)
		cvtColor(dst, dst, CV_BGR2GRAY);


	/// GAUSSIAN FILTER
	//dst = myConvolution(dst, myGaussianKernel(), BLUR);


	Mat sobel1 = myConvolution(dst, mySobelKernel(), DERIVATIVE);
	Mat sobel2 = myConvolution(dst, mySobelKernel(HORIZONTAL), DERIVATIVE);


	Mat magnitude = myMatrixOperation(sobel1, sobel2, MAGNITUDE);
	Mat angle = myMatrixOperation(sobel1, sobel2, DIRECTION);


/*	imshow("1", sobel1);
	imshow("2", sobel2);
	imshow("3", magnitude);
	imshow("4", angle);
	waitKey(0);*/

}
