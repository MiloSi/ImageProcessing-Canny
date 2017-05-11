#pragma once
#include <opencv2\opencv.hpp>
#include <iostream>

#include "myCalculation.h"

using namespace cv;
using namespace std;


enum ORIENTATION{ VERTICAL = 1,  HORIZONTAL = 2};
enum DERIVATIVE { MY_PRWITT = 1, MY_SOBEL = 2 };

Mat derivative(const Mat src,  ORIENTATION orientation, DERIVATIVE flag);



class myDerivative {

public : 
	myDerivative(const Mat src, ORIENTATION  orientation, DERIVATIVE flag );
	~myDerivative();
private :

	Mat mySobel();
	Mat myPrewitt();

	const Mat& src;



	uchar prwitt1[3][3] = {
		{ 1,1,1 },
		{ 0,0,0 },
		{ -1,-1,-1 }
	};
	uchar prwitt2[3][3] = {
		{ 1, 0,-1 },
		{ 1, 0,-1 },
		{ 1, 0,-1 }
	};
	uchar sobel1[3][3] = {
		{ 1,2,1 },
		{ 0,0,0 },
		{ -1,-2,-1 }
	};
	uchar sobel2[3][3] = {
		{ 1,0, -1 },
		{ 2,0, -2 },
		{ 1,0,-1 }
	};

};
