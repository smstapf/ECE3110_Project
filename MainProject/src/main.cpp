#include "pendulum.h"

using namespace std;

//Threads
void* cameraCaptureThread(void*);
void* imageProcessingThread(void*);

//Shared buffers
pthread_mutex_t frameMutex, orientationMutex;
vector<Mat> frameBuffer;                //Shared image buffer
double orientation;                      //Shared orientation

//Global variables/objects
Camera camera = Camera();               //Global camera object
ImageProcessor ip = ImageProcessor();   //Global image processing object


int main(int argc, char**  argv){ 

    pthread_t cameraThread, ipThread;
    ip.setHighThresh(150);
    ip.setLowThresh(100);
    ip.setKernel(3);
    pthread_create(&ipThread, NULL, imageProcessingThread, NULL);
	pthread_create(&cameraThread, NULL, cameraCaptureThread, NULL);

    cin.get();
    pthread_join(cameraThread, NULL);
    pthread_join(ipThread, NULL);
    return(0);
}

void* cameraCaptureThread(void*){
    cout<<"Camera Capture Thread"<<endl;
    //Bump priority to the top
    struct sched_param param;
	param.sched_priority = 48;
	sched_setscheduler(0,SCHED_FIFO,&param);


    //Capture as fast as possible? maybe a timer

    //Capture image
    camera.captureImage();
    //lock the mutex
	pthread_mutex_lock(&frameMutex);
    //add to the buffer
    cout<<"test"<<endl;
    frameBuffer.push_back(camera.getImage());
    //unlock the mutex
    pthread_mutex_unlock(&frameMutex);
    camera.displayImage();
}

void* imageProcessingThread(void*){
    //cout<<"Image Processing Thread"<<endl;
    //Bump priority to the top
    struct sched_param param;
	param.sched_priority = 48;
	sched_setscheduler(0,SCHED_FIFO,&param);

    Mat image;
    vector<Vec2f> lines;
    double tempOrientation;
    //lock mutex
    while(frameBuffer.size() <= 0){
    }
    pthread_mutex_lock(&frameMutex);
    //grab image from shared buffer
    image = frameBuffer[0];
    frameBuffer.pop_back();
    //unlock mutex
    pthread_mutex_unlock(&frameMutex);
    //process
    ip.loadImage(image);
    ip.toGray();
    ip.cannyFilter();
    ip.hTransform();
    lines = ip.getLines();
    for(int i = 0; i < lines.size(); i++){
        tempOrientation += lines[i][1];
    }
    tempOrientation /= lines.size();
    //lock mutex
    pthread_mutex_lock(&orientationMutex);
    //write to orientation buffer
    orientation = tempOrientation;
    //unlock mutex
    pthread_mutex_unlock(&orientationMutex);
    cout<<"orientation: "<<orientation<<endl;
}