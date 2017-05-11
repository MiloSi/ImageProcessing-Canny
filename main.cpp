
/*********************************************** 
2017 - 05 - 10
	Created by Milo Si(Call me C)
	I studied Image Processing
	and Implemented Canny Edge using OpenCV.

	From Wikipeida 
	1. Apply Gaussian filter to smooth the image in order to remove the noise
	2. Find the intensity gradients of the image
	3. Apply non - maximum suppression to get rid of spurious response to edge detection
	4. Apply double threshold to determine potential edges
	5. Track edge by hysteresis : 
		Finalize the detection of edges by suppressing all the other edges that are weak and not connected to strong edges.


	From OpenCV http://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/canny_detector/canny_detector.html



***********************************************/


#pragma once

#include <iostream>
#include "myGaussian.h"
#include "myDerivative.h"
#include <opencv2\opencv.hpp>



using namespace std;
using namespace cv;


int main(int argc, char* argv[])
{

	return 0;
}

