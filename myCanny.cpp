#pragma once
#include "myCanny.h"
#include "myCalculation.h"


void myCannyEdge(Mat src, Mat& dst, double lowerThreshold, double upperThreshold)
{

	if (src.type() != CV_8UC1)
		cvtColor(src, src, CV_BGR2GRAY);


	/// GAUSSIAN FILTER
	Mat gaussian = myConvolution(src, myGaussianKernel(Size(5,5), 0.5), BLUR);

	Mat sobelY = myConvolution(gaussian, mySobelKernel(VERTICAL), DERIVATIVE);  // Y
	Mat sobelX = myConvolution(gaussian, mySobelKernel(HORIZONTAL), DERIVATIVE); // X


	/*
	Mat sobelY, sobelX;
	Sobel(gaussian, sobelX, CV_64F, 1, 0);
	Sobel(gaussian, sobelY, CV_64F, 0, 1);
	*/

	Mat magnitude = myMatrixOperation(sobelY, sobelX, MAGNITUDE);
	Mat angle = myMatrixOperation(sobelY, sobelX, magnitude, DIRECTION);


	imshow("1", sobelY);
 	imshow("2", sobelX);
//	imshow("3", magnitude);
//	imshow("4", angle);
	dst = myTraceEdge(magnitude, angle, lowerThreshold, upperThreshold);
	imshow("5", dst);
	myRemoveWeakEdge(dst);

	

	//3. Apply non - maximum suppression to get rid of spurious response to edge detection





	//waitKey(0);

}