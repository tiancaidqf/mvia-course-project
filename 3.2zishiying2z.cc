#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
int main( )
{
  // 图像读取
  cv::Mat srcImage = cv::imread("2.jpeg");
  cv::Mat srcGray;
  cv::cvtColor(srcImage, srcGray, CV_RGB2GRAY);
  cv::Mat result;
  // 初始化自适应阈值参数
  int blockSize = 5;
  int constValue = 10;
  const int maxVal = 255;
    /* 自适应阈值算法
  0：ADAPTIVE_THRESH_MEAN_C
  1: ADAPTIVE_THRESH_GAUSSIAN_C
  阈值类型
  0: THRESH_BINARY
  1: THRESH_BINARY_INV */
  int adaptiveMethod = 0;
  int thresholdType = 1;
  // 图像自适应阈值操作
  cv::adaptiveThreshold(srcGray, result,maxVal, adaptiveMethod,thresholdType, blockSize,constValue);
  cv::imshow("result", result);
  cv::waitKey(0);
  return 0;

}
