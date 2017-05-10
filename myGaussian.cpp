#include "myGaussian.h"

template <typename T>
inline T MULT(T value) {
	return value*value;
};
template <typename T>
inline T MULT(T value1, T value2)
{
	return (value1 * value1) + (value2 * value2);
};



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


Mat gaussianFilter(const Mat src, const Size nSize, const double sigma)
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

	Mat dst(src.rows, src.cols, src.type);

	for (int y = half_y; y < src.rows; y++) {
		for (int x = half_x; x < src.cols; x++) {
			Mat pixel_group(src, Rect(x - half_x, y - half_y, nSize.width, nSize.height));
			dst.at<uchar>(y, x) = calculation(kernel, pixel_group.clone());
		}

	}
	return dst;
}
