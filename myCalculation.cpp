#include  "myCalculation.h"
#include  "myKernel.h"

Mat myMatrixOperation(Mat& mat1, Mat& mat2, OPERATION flag)
{
	Mat dst(mat1.rows, mat2.cols, CV_32F);

	
	switch (flag)
	{
	case MAGNITUDE:

		for (int y = 1; y < mat1.rows -1; y++)
		{
			float* ptr1 = mat1.ptr<float>(y);
			float* ptr2 = mat2.ptr<float>(y);
			float* dstPtr = dst.ptr<float>(y);

			for (int x = 1; x < mat1.cols -1; x++)
			{
				float p = sqrt(MULT<float>(ptr1[x], ptr2[x]));
				dstPtr[x] = p;
			}
		}

		break;
	case DIRECTION:
		dst = Mat(mat1.rows, mat1.cols, CV_8U);
		for (int y = 1; y < mat1.rows -1; y++)
		{
			float* ptr1 = mat1.ptr<float>(y);
			float* ptr2 = mat2.ptr<float>(y);
			uchar* dstPtr = dst.ptr<uchar>(y);



			for (int x = 1; x < mat1.cols -1; x++)
			{
				//float p = atan2(ptr1[x], ptr2[x]) * 180.0f / CV_PI;
				float p;
				if (ptr2[x] == 0)
					p = 90;
				else
				 p = atan(ptr1[x] / ptr2[x]) * 180 / CV_PI;
				
				p /= 22.5;
				//p = (p < 0) ? 8 + p : p;
				if (p > 7) p = 0;
				if (p < 1 || p > 7) { dstPtr[x] = 0; }
				else if (p < 3) { dstPtr[x] = 45; }
				else if (p < 5) { dstPtr[x] = 90; }
				else if (p < 7){ dstPtr[x] = 135; }
				
			}
		}
		break;

	default:
		break;
	}

	return dst;
}

Mat myTraceEdge(Mat& gradient, Mat& direction, double lowerThreshold, double upperThreshold)
{

	Mat dst(gradient.rows, gradient.cols, CV_8U, Scalar(0));
	uchar ptr_value;
	vector<Point2i> strongEdgePoints;

	for (int y = 1; y < gradient.rows - 1; y++)
	{
		uchar* dptr = direction.ptr<uchar>(y);
		float* gptr = gradient.ptr<float>(y);
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
					if (gradient.at<float>(y, x - 1) <= ptr_value && gradient.at<float>(y, x + 1) < ptr_value)
						isMax = true;
					break;
				case 45:
					if (gradient.at<float>(y - 1, x - 1) <= ptr_value && gradient.at<float>(y + 1, x + 1) < ptr_value)
						isMax = true;
					break;
				case 90:
					if (gradient.at<float>(y - 1, x) <= ptr_value && gradient.at<float>(y + 1, x) < ptr_value)
						isMax = true;
					break;
				case 135:
					if (gradient.at<float>(y - 1, x + 1) <= ptr_value && gradient.at<float>(y + 1, x - 1) < ptr_value)
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
				if (dst.at<uchar>(x,y) == 128)
				{
					dst.at<uchar>(x, y) = 255;
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