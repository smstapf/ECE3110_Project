#include "opencv2/opencv.hpp"
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>

using namespace cv;

int main(int argc, char** argv)
{
    VideoCapture cap(1); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;
    Mat frame;
    int which = PRIO_PROCESS;
    id_t pid;
    int ret;

    pid = getpid();
    ret = getpriority(which, pid);
    std::cout<<"Priority before "<< ret << std::endl;

    int priority = -20;
    ret = setpriority(which, pid, priority);
    ret = getpriority(which, pid);
    std::cout<<"Priority after " << ret << std::endl;
    for(int i = 0;i < 100; i++)
    {
        cap >> frame; // get a new frame from camera
        std::cout<<"Frame : " << i << std::endl;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
