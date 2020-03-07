#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
using namespace cv;
using namespace std;


int thresholds=100;
Mat srcImage;
Mat result;

static void on_threshold(int,void*)
{
threshold(srcImage,result,thresholds,255,CV_THRESH_BINARY);
imshow("2zh",result);
}//dingyihaoyigehuitiaohanshu




int main()

{

        srcImage=imread("2.jpeg",0);

        namedWindow("2zh",WINDOW_AUTOSIZE);

        cv::createTrackbar("ts","2zh",&thresholds,255,on_threshold);//guidao(guidaotiaoqianmiandemingzi,chuangkouming,niyaotiaodecanshudemingzi,zuidazhi,huitiaohanshudemingzi)

        on_threshold(0,0);//huitiaohanshu

        waitKey(0);
        return 0;

}
