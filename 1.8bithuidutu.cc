#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
using namespace cv;  


int main()

{


        Mat srcImage=imread("2.jpeg",0);
        imshow( "8huidutu", srcImage );
        
        waitKey(0);
        return 0;

}
