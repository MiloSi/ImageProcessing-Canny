#include "myDerivative.h"


myDerivative::myDerivative(const Mat src, ORIENTATION orientation, DERIVATIVE flag) : src(src) {


	Mat matrix;


	switch (flag)
	{
	case MY_PRWITT:
		if (orientation == VERTICAL)
			matrix = Mat(3, 3, CV_8UC1, &prwitt1);
		else
			matrix = Mat(3, 3, CV_8UC1, &prwitt2);
		break;
	case MY_SOBEL:
		if (orientation == VERTICAL)
			matrix = Mat(3, 3, CV_8UC1, &sobel1);
		else
			matrix = Mat(3, 3, CV_8UC1, &sobel2);
		break;
	default:
		break;
	}



}


Mat myDerivative::mySobel()
{
	Mat matrix;
	Mat dst(src.rows, src.cols, src.type);






	calculation(src, matrix);
}
Mat myDerivative::myPrewitt()
{


}


Mat sobel(const Mat src, int gx) 
{



}
Mat prewitt(const Mat src) 
{

}

Mat derivative(const Mat src, ORIENTATION orientation = VERTICAL, DERIVATIVE flag = MY_SOBEL)
{

}