#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main( int, char** argv )
    {
        Mat src,gray,Kernelx,Kernely;

        src = imread("2.jpeg");
        cvtColor( src, gray, CV_RGB2GRAY );
        namedWindow("srcImage", 1);
        namedWindow("dstImage", 1);

        Kernelx = (Mat_<double>(3,3) << 1, 1, 1, 0, 0, 0, -1, -1, -1);
        Kernely = (Mat_<double>(3,3) << -1, 0, 1, -1, 0, 1, -1, 0, 1);

        Mat grad_x, grad_y;
        Mat abs_grad_x, abs_grad_y, grad;

        filter2D(gray, grad_x, CV_16S , Kernelx, Point(-1,-1));
        filter2D(gray, grad_y, CV_16S , Kernely, Point(-1,-1));
        convertScaleAbs( grad_x, abs_grad_x );
        convertScaleAbs( grad_y, abs_grad_y );

        addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );
        imshow("dstImage", grad);

        waitKey(0);
        return 0;
    }

