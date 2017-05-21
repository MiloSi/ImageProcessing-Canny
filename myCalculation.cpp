#include  "myCalculation.h"
#include  "myKernel.h"

Mat myMatrixOperation(Mat& mat1, Mat& mat2, OPERATION flag)
{
	Mat dst(mat1.rows, mat2.cols, CV_64F);;

	
	switch (flag)
	{
	case MAGNITUDE:

		for (int y = 1; y < mat1.rows -1; y++)
		{
			double* ptr1 = mat1.ptr<double>(y);
			double* ptr2 = mat2.ptr<double>(y);
			double* dstPtr = dst.ptr<double>(y);

			for (int x = 1; x < mat1.cols -1; x++)
			{
				//double p = sqrt(MULT<double>(ptr1[x], ptr2[x]));
				double p = sqrt(ptr1[x] * ptr1[x] + ptr2[x] * ptr2[x]);

				dstPtr[x] = p;
			}
		}
		break;

	default:
		break;
	}

	return dst;
}


Mat myMatrixOperation(Mat& sobelY, Mat& sobelX, const Mat magnitude, OPERATION flag)
{
	Mat dst;


	switch (flag)
	{
	case DIRECTION:
		dst = Mat(sobelY.rows, sobelY.cols, CV_8U);
		for (int y = 1; y < sobelY.rows - 1; y++)
		{
			double* ptr1 = sobelY.ptr<double>(y);
			double* ptr2 = sobelX.ptr<double>(y);
			uchar* dstPtr = dst.ptr<uchar>(y);

			for (int x = 1; x < sobelY.cols - 1; x++)
			{
				//float p = atan2(ptr1[x], ptr2[x]) * 180.0f / CV_PI;
				double p;
				if (ptr2[x] == 0)
					p = 90.0;
				else {
					p = atan2(ptr1[x], ptr2[x]) * 180.0 / CV_PI;
				}
				
				if ((p > -22.5 && p < 22.5) || p > 157.5 || p < -157.5) dstPtr[x] = 0;
				else if ((p >= 22.5 && p < 67.5) || (p >= -157.5 && p < -112.5)) dstPtr[x] = 45;
				else if ((p > 67.5 && p < 112.5) || (p >= -112.5 && p <= -67.5)) dstPtr[x] = 90;
				else dstPtr[x] = 135;
		
			}
		}
		break;

	default:
		break;
	}

	return dst;
}

Mat myTraceEdge(Mat& gradient, Mat& direction, const double lowerThreshold, const double upperThreshold)
{

	Mat dst(gradient.rows, gradient.cols, CV_8U, Scalar(0));
	uchar ptr_value;
	vector<Point2i> strongEdgePoints;

	for (int y = 1; y < gradient.rows - 1; y++)
	{
		uchar* dptr = direction.ptr<uchar>(y);
		double* gptr = gradient.ptr<double>(y);
		uchar* dst_ptr = dst.ptr(y);

		for (int x = 1; x < gradient.cols -1; x++)
		{
			ptr_value = gptr[x];

			if (ptr_value > lowerThreshold)
			{

				bool isMax = false;

				switch (dptr[x])
				{
				case 0:
					if ((gradient.at<double>(y, x - 1) < ptr_value) && (gradient.at<double>(y, x + 1)) < ptr_value)
						isMax = true;
					break;
				case 45:
					if ((gradient.at<double>(y - 1, x - 1) < ptr_value) && (gradient.at<double>(y + 1, x + 1)) < ptr_value)
						isMax = true;
					break;
				case 90:
					if ((gradient.at<double>(y - 1, x) < ptr_value) && (gradient.at<double>(y + 1, x)) < ptr_value)
						isMax = true;
					break;
				case 135:
					if ((gradient.at<double>(y - 1, x + 1) < ptr_value) && (gradient.at<double>(y + 1, x - 1)) < ptr_value)
						isMax = true;
					break;
				}

				if (isMax)
				{
					if (ptr_value > upperThreshold) {
						dst_ptr[x] = 255;
						strongEdgePoints.push_back(Point2i(x,y));
					}
					else
						dst_ptr[x] = 128;
				}
			}
		}
	}

	while (!strongEdgePoints.empty())
	{
		Point2i point = strongEdgePoints.back();
		strongEdgePoints.pop_back();

		for (int y = point.y - 1; y < point.y + 1; y++) 
		{
			for (int x = point.x - 1; x < point.x + 1; x++)
			{

				if (x == point.x && y == point.y)
					continue;
				if (dst.at<uchar>(y,x) == 128)
				{
					dst.at<uchar>(y,x) = 255;
					strongEdgePoints.push_back(Point2i(x, y));
				}
			}
		}
	}

	return dst;
}

void myRemoveWeakEdge(Mat& dst)
{
	for (int y = 1; y < dst.rows - 1; y++)
	{
		uchar* ptr = dst.ptr(y);
		for (int x = 1; x < dst.cols -1 ; x++)
		{
			if (ptr[x] == 128)
				ptr[x] = 0;
		}
	}
}