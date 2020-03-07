#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>


using namespace cv;

int main( )
{

        Mat grad_x, grad_y;
        Mat abs_grad_x, abs_grad_y,result;


        Mat srcImage = imread("2.jpeg");
        imshow("原图", srcImage);


        Sobel( srcImage, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT );
        convertScaleAbs( grad_x, abs_grad_x );//求 X方向梯度
        imshow("X方向Sobel", abs_grad_x);


        Sobel( srcImage, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT );
        convertScaleAbs( grad_y, abs_grad_y );
        imshow("Y方向Sobel", abs_grad_y);//求Y方向梯度


        addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, result);
        imshow("整体方向Sobel", result);  //合并梯度

        waitKey(0);
        return 0;
}

