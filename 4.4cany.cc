#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;


int main( )
{

        Mat srcImage = imread("2.jpeg");
        imshow("原图", srcImage); 	//显示原始图
        Mat dstImage,edge,grayImage;	//参数定义


        dstImage.create( srcImage.size(), srcImage.type() );//创建与src同类型和大小的矩阵(dst)

        cvtColor( srcImage, grayImage, COLOR_BGR2GRAY );//将原图像转换为灰度图像


        blur( grayImage, edge, Size(3,3) );//先用使用 3x3内核来降噪


        Canny( edge, edge, 3, 9,3 );//运行Canny算子
        imshow("Canny边缘检测", edge);

        waitKey(0);

        return 0;
}
