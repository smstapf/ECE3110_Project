#include "opencv2/opencv.hpp"

using namespace cv;
#define LOW_THRESHOLD 10
#define HIGH_THRESHOLD 100
#define KERNEL 3


int main(int argc, char** argv){

  VideoCapture cap(0); // open the default camera
  if(!cap.isOpened())  // check if we succeeded
      return -1;

  Mat frame;
  Mat frame_gray;
  cap >> frame; //Grab an image

  cvtColor(frame, frame_gray, COLOR_BGR2GRAY );

  Mat dst;
  Canny(frame_gray, dst, LOW_THRESHOLD, HIGH_THRESHOLD, KERNEL);

  imshow("edges", dst);
  while(waitKey(30) < 0){

  }
  return(0);
}
