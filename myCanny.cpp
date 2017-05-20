#pragma once
#include "myCanny.h"
#include "myCalculation.h"


void myCannyEdge(Mat src, Mat& dst, double lowerThreshold, double upperThreshold)
{

	if (src.type() != CV_8UC1)
		cvtColor(src, src, CV_BGR2GRAY);


	/// GAUSSIAN FILTER
	Mat gaussian = myConvolution(src, myGaussianKernel(Size(5,5), 0.5), BLUR);


	
	Mat sobel1 = myConvolution(gaussian, mySobelKernel(VERTICAL), DERIVATIVE);
	Mat sobel2 = myConvolution(gaussian, mySobelKernel(HORIZONTAL), DERIVATIVE);

	Mat magnitude = myMatrixOperation(sobel1, sobel2, MAGNITUDE);
	Mat angle = myMatrixOperation(sobel1, sobel2, DIRECTION);


//	imshow("1", sobel1);
// 	imshow("2", sobel2);
//	imshow("3", magnitude);
//	imshow("4", angle);
	dst = myTraceEdge(magnitude, angle, lowerThreshold, upperThreshold);
	imshow("5", dst);
	myRemoveWeakEdge(dst);

	

	//3. Apply non - maximum suppression to get rid of spurious response to edge detection





	//waitKey(0);

}