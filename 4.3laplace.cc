#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;


int main( )
{

        Mat src_gray,result,abs_result;


        Mat srcImage = imread("2.jpeg");

        imshow("原图", srcImage);

        GaussianBlur( srcImage, srcImage, Size(3,3), 0, 0, BORDER_DEFAULT );//高斯滤波去噪

        cvtColor( srcImage, src_gray, COLOR_RGB2GRAY );//转换为灰度图


        Laplacian( src_gray, result, CV_16S, 3, 1, 0, BORDER_DEFAULT );//Laplace函数


        convertScaleAbs( result, abs_result );//计算绝对值，并将结果转换成8位

        imshow( "Laplace变换", abs_result );

        waitKey(0);

        return 0;
}
