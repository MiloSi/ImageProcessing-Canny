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
				dstPtr[x] = (uchar)p;
			}
		}
		break;

	default:
		break;
	}

	return dst;
}