#include "pendulum.h"

using namespace std;


int main(int argc, char**  argv){
    Motor motor = Motor();
    Camera camera = Camera();
    Accelerometer accelerometer = Accelerometer();
    ImageProcessor ip = ImageProcessor();

    //camera.streamImage();
    cout<<"test"<<endl;
    ip.setHighThresh(150);
    ip.setLowThresh(100);
    ip.setKernel(3);

    //camera.streamImage();

    
    while(1){
        camera.captureImage();
        ip.loadImage(camera.getImage());
        //ip.toGray();
        //imshow("test", ip.getProcessedImage());
       // waitKey(0);
        ip.toGray();
        ip.cannyFilter();
        ip.hTransform();
        ip.drawLines();
        if(waitKey(30) >= 0){
            return(0);
        }
    }
    return(0);
}