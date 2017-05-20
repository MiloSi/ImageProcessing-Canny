#pragma once
#include "myConvolution.h"
#include "myKernel.h"



float calculation1(const Mat kernel, Mat pixels)
{
	float dst = 0;
	pixels.convertTo(pixels, CV_32F);

	for (int i = 0; i < pixels.rows; i++)
	{
		for (int j = 0; j < pixels.cols; j++)
		{
			dst += pixels.at<float>(i, j) * kernel.at<float>(i, j);
		}

	}
	return dst;
}

float calculation2(const Mat kernel, Mat pixels)
{
	float dst = 0;

	for (int i = 0; i < pixels.rows; i++)
	{
		for (int j = 0; j < pixels.cols; j++)
		{
			int a = (int)kernel.at<int>(i, j);
			float b = (float)pixels.at<float>(i, j);

			dst += a*b;
		}

	} 
	return dst;
}

Mat myConvolution(const Mat src, Mat& kernel, FILTERING flag)
{

	Mat dst;
	dst = Mat(src.rows, src.cols, CV_32F);
	int x_half = kernel.cols >> 1;
	int y_half = kernel.rows >> 1;
	switch (flag)
	{
	case BLUR:

		for (int y = y_half; y < src.rows - y_half; y++)
		{
			float* ptr = dst.ptr<float>(y);
			for (int x = x_half; x < src.cols - x_half; x++)
			{
				Mat pixels(src, Rect(x - x_half, y - y_half, kernel.cols, kernel.rows));
				ptr[x] = calculation1(kernel, pixels);
			}
		}
		break;


	case DERIVATIVE:


		for (int y = 1; y < src.rows - 1; y++)
		{
			float* ptr = dst.ptr<float>(y);
			for (int x = 1; x < src.cols - 1; x++)
			{
				Mat pixels(src, Rect(x - 1, y - 1, kernel.cols, kernel.rows));
				ptr[x] = calculation2(kernel, pixels);
			}
		}
		break;
	
	}

	return dst;
}
