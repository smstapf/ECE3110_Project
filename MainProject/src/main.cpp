#include "pendulum.h"

using namespace std;


int main(int argc, char**  argv){
    Motor motor = Motor();
    Camera camera = Camera();
    Accelerometer accelerometer = Accelerometer();
    ImageProcessor ip = ImageProcessor();

    //camera.streamImage();
    cout<<"test"<<endl;
    
    camera.captureImage();
    ip.loadImage(camera.getImage());
    ip.toGray();
    

    imshow("test", ip.getProcessedImage());

    waitKey(0);
    ip.setHighThresh(300);
    ip.setLowThresh(200);
    ip.setKernel(3);
    ip.canny();

    imshow("test", ip.getProcessedImage());
    
    waitKey();
  //  Mat lines;
    /*HoughLines(ip.getProcessedImage(), lines, 100, 3.14, 1);

    imshow("test", lines);

    waitKey(0);
*/
    return(0);
}