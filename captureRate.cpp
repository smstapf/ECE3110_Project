#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char** argv)
{
    VideoCapture cap(1); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat frame;
    for(int i = 0;i < 1000; i++)
    {
        cap >> frame; // get a new frame from camera
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
