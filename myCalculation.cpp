#include "myCalculation.h"





uchar calculation(Mat kernel, Mat pixel)
{
	float dst = 0;
	pixel.convertTo(pixel, CV_32F);

	for (int i = 0; i < pixel.rows; i++)
	{
		for (int j = 0; j < pixel.cols; j++)
		{
			dst += pixel.at<float>(i, j) * kernel.at<float>(i, j);
		}

	}
	return (uchar)dst;
}

uchar calculation(Mat kernel, Mat pixel)
{
	uchar dst = 0;

	for (int i = 0; i < pixel.rows; i++)
	{
		for (int j = 0; j < pixel.cols; j++)
		{
			dst += pixel.at<uchar>(i, j) * kernel.at<uchar>(i, j);
		}

	}
	return dst;
}

