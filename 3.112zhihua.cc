#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
using namespace cv;
using namespace std;


int main()

{
    Mat srcImage;
    Mat result;


        srcImage=imread("2.jpeg",0);
        threshold(srcImage,result,127,255,CV_THRESH_BINARY);
        imshow( "2zhihua", result);
        waitKey(0);
        return 0;

}

