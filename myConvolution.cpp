#pragma once
#include "myConvolution.h"



uchar calculation1(const Mat kernel, Mat pixels)
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
	return (uchar)dst;
}

uchar calculation2(const Mat kernel, Mat pixels)
{
	int dst = 0;

	for (int i = 0; i < pixels.rows; i++)
	{
		for (int j = 0; j < pixels.cols; j++)
		{
			dst += pixels.at<uchar>(i, j) * kernel.at<uchar>(i, j);
		}

	}
	return (uchar)dst;
}

Mat myConvolution(const Mat src, const Mat kernel, FILTERING flag)
{

	Mat dst(src.rows, src.cols, src.type());
	int x_half = kernel.cols >> 1;
	int y_half = kernel.rows >> 1;

	switch (flag)
	{
	case BLUR :
		for (int y = y_half; y < src.rows - y_half; y++)
		{
			uchar* ptr = dst.ptr(y);
			for (int x = x_half; x < src.cols - x_half; x++)
			{
				Mat pixels(src, Rect(x - x_half, y - y_half, kernel.cols, kernel.rows));
				ptr[x] = calculation1(kernel, pixels);
			}
		}
		break;


	case DERIVATIVE :
		for (int y = y_half; y < src.rows - y_half; y++)
		{
			uchar* ptr = dst.ptr(y);
			for (int x = x_half; x < src.cols - x_half; x++)
			{
				Mat pixels(src, Rect(x - x_half, y - y_half, kernel.cols, kernel.rows));
				ptr[x] = calculation2(kernel, pixels);
			}
		}
		break;
	}

	return dst;
}
