#include  "myCalculation.h"
#include  "myKernel.h"

Mat myMatrixOperation(Mat& mat1, Mat& mat2, OPERATION flag)
{
	Mat dst(mat1.rows, mat2.cols, mat1.type());

	
	switch (flag)
	{
	case MAGNITUDE:

		for (int y = 0; y < mat1.rows; y++)
		{
			uchar* ptr1 = mat1.ptr<uchar>(y);
			uchar* ptr2 = mat2.ptr<uchar>(y);
			uchar* dstPtr = dst.ptr<uchar>(y);

			for (int x = 0; x < mat1.cols; x++)
			{
				float p = sqrt(MULT<float>(ptr1[x], ptr2[x]));
				dstPtr[x] = (uchar)p;
			}
		}

		break;
	case DIRECTION:

		for (int y = 0; y < mat1.rows; y++)
		{
			uchar* ptr1 = mat1.ptr<uchar>(y);
			uchar* ptr2 = mat2.ptr<uchar>(y);
			uchar* dstPtr = dst.ptr<uchar>(y);



			for (int x = 0; x < mat1.cols; x++)
			{
				float p = atan2((float)ptr1[x], (float)ptr2[x]) * 180.0f / CV_PI;
				p /= 8;
				p = (p < 0) ? 8 + p : p;
				if (p < 1 || p > 7) { p = 0; }
				else if (p < 3) { p = 45; }
				else if (p < 5) { p = 90; }
				else { p = 135; }
				
				dstPtr[x] = (uchar)p;
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

	Mat dst(gradient.rows, gradient.cols, gradient.type(), Scalar(0));

	for (int y = 1; y < gradient.rows - 1; y++)
	{
		uchar* dptr = direction.ptr(y);
		for (int x = 1; x < gradient.cols -1; x++)
		{

			bool isMax = false;
			switch (dptr[x])
			{
			case 0 :
				if (direction.at<uchar>(y, x - 1) >= lowerThreshold && direction.at<uchar>(y, x + 1) > lowerThreshold)
					isMax = true;
				break;
			case 45:
				if (direction.at<uchar>(y-1, x - 1) >= lowerThreshold && direction.at<uchar>(y +1, x + 1) >  lowerThreshold)
					isMax = true;
				break;
			case 90:
				
				if (direction.at<uchar>(y - 1, x ) >= lowerThreshold && direction.at<uchar>(y +1, x ) >  lowerThreshold)
					isMax = true;
				break;
			case 135:
				if (direction.at<uchar>(y - 1, x + 1) >= lowerThreshold && direction.at<uchar>(y + 1, x - 1) >  lowerThreshold)
					isMax = true;
				break;
			}

			if(isMax)

		}
	}

}