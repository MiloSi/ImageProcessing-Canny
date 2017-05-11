#include "myKernel.h"

Mat myGaussianKernel(const Size nSize =  Size(5, 5) , const float sigma = 1.4)
{
	Mat kernel(nSize, CV_32F);
	int half_x = nSize.width >> 1;
	int half_y = nSize.height >> 1;

	for (int y = 0; y < nSize.height; y++)
	{
		for (int x = 0; x < nSize.width; x++)
		{
			float kernel_x = x - half_x;
			float kernel_y = y - half_y;

			kernel.at<float>(y, x)
				= exp(-MULT<float>(kernel_y, kernel_x) / (2 * MULT<float>(sigma)))
				/ (2 * CV_PI * MULT<float>(sigma));
		}
	}

	return kernel;
}
Mat myPrwittKernel(ORIENTATION flag = VERTICAL, int weight = 1)
{
	Mat kernel;
	switch (flag)
	{
	case VERTICAL:
		kernel = Mat(3, 3, CV_8UC1, &prwitt1);
		break;
	case HORIZONTAL:
		kernel = Mat(3, 3, CV_8UC1, &prwitt2);
		break;
	}
	return kernel;
}
Mat mySobelKernel(ORIENTATION flag = VERTICAL, int weight = 1)
{
	Mat kernel;
	switch (flag)
	{
	case VERTICAL:
		kernel = Mat(3, 3, CV_8UC1, &sobel1);
		break;
	case HORIZONTAL:
		kernel = Mat(3, 3, CV_8UC1, &sobel2);
		break;
	}
	return kernel;
}

