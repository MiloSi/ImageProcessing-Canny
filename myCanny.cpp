#pragma once
#include "myCanny.h"
#include "myCalculation.h"


void myCannyEdge(Mat src, Mat& dst, double lowerThreshold, double upperThreshold)
{

	if (src.type() != CV_8UC1)
		cvtColor(src, src, CV_BGR2GRAY);


	/// GAUSSIAN FILTER
	src = myConvolution(src, myGaussianKernel(Size(5,5), 1), BLUR);



	Mat sobel1 = myConvolution(src, mySobelKernel(VERTICAL), DERIVATIVE);
	Mat sobel2 = myConvolution(src, mySobelKernel(HORIZONTAL), DERIVATIVE);

/*
	Mat sobel1, sobel2;

	Sobel(src, sobel1, 0, 0, 1);
	Sobel(src, sobel2, 0, 1, 0);
*/

	
	

	imshow("0", src);



	Mat magnitude = myMatrixOperation(sobel1, sobel2, MAGNITUDE);
	Mat angle = myMatrixOperation(sobel1, sobel2, DIRECTION);


//	imshow("1", sobel1);
//	imshow("2", sobel2);
//	imshow("3", magnitude);
//	imshow("4", angle);
	dst = myTraceEdge(magnitude, angle, lowerThreshold, upperThreshold);
	imshow("5", dst);
	myRemoveWeakEdge(dst);

	

	//3. Apply non - maximum suppression to get rid of spurious response to edge detection





	//waitKey(0);

}