#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    // image.pngをimgに代入
    cv::Mat img = cv::imread("../image.jpg");
    std::cout << "opened image.jpg" << std::endl;
    return 0;
}