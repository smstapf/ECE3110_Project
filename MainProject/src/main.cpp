#include "pendulum.h"

using namespace std;

//Threads
void* cameraCaptureThread(void*);
void* imageProcessingThread(void*);

//Shared buffers
pthread_mutex_t frameMutex, orientationMutex;
sem_t orientationSemaphore;
vector<Mat> frameBuffer;                //Shared image buffer
double orientation;                      //Shared orientation

//Global variables/objects
Camera camera = Camera();               //Global camera object
ImageProcessor ip = ImageProcessor();   //Global image processing object
Motor motor = Motor();


int main(int argc, char**  argv){ 

    pthread_t cameraThread, ipThread;
    sem_init(&orientationSemaphore, 0, 0);
    ip.setHighThresh(100);
    ip.setLowThresh(50);
    ip.setKernel(3);
    pthread_create(&ipThread, NULL, imageProcessingThread, NULL);
	pthread_create(&cameraThread, NULL, cameraCaptureThread, NULL);

    while(1){
        sem_wait(&orientationSemaphore);
        cout<<"Orientation: "<<orientation<<endl;
    }
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
    while(1){
        //Capture image
        camera.captureImage();
        //lock the mutex
        pthread_mutex_lock(&frameMutex);
        //cout<<"camera lock"<<endl;
        //add to the buffer
        //cout<<"test"<<endl;
        frameBuffer.push_back(camera.getImage());
        //unlock the mutex
        pthread_mutex_unlock(&frameMutex);
        //cout<<"Camera unlock"<<endl;
        //camera.displayImage();
        //waitKey(0);
    }
}

void* imageProcessingThread(void*){
    //cout<<"Image Processing Thread"<<endl;
    //Bump priority to the top
    struct sched_param param;
	param.sched_priority = 48;
	sched_setscheduler(0,SCHED_FIFO,&param);


    //lock mutex
    while(1){
        Mat image;
        Mat cdst;
        vector<Vec2f> lines;
        double tempOrientation = 0;
        while(frameBuffer.size() <= 0){
        }
        pthread_mutex_lock(&frameMutex);
        //cout<<"IP lock"<<endl;
        //grab image from shared buffer
        image = frameBuffer[0];
        frameBuffer.pop_back();
        //unlock mutex
        pthread_mutex_unlock(&frameMutex);
        //cout<<"IP unlock"<<endl;
        //process
        ip.loadImage(image);
        ip.toGray();
        ip.cannyFilter();
        cvtColor(ip.getProcessedImage(), cdst, CV_GRAY2BGR);
        ip.hTransform();
        lines = ip.getLines();
        for(int i = 0; i < lines.size(); i++){
            tempOrientation += lines[i][1];


            float rho = lines[i][0], theta = lines[i][1];
            Point pt1, pt2;
            double a = cos(theta), b = sin(theta);
            double x0 = a*rho, y0 = b*rho;
            pt1.x = cvRound(x0 + 1000*(-b));
            pt1.y = cvRound(y0 + 1000*(a));
            pt2.x = cvRound(x0 - 1000*(-b));
            pt2.y = cvRound(y0 - 1000*(a));
            line( cdst, pt1, pt2, Scalar(0,0,255), 3, CV_AA);
        }
        tempOrientation /= lines.size();
        //lock mutex
        pthread_mutex_lock(&orientationMutex);
        //write to orientation buffer
        orientation = tempOrientation;
        //unlock mutex
        pthread_mutex_unlock(&orientationMutex);
        sem_post(&orientationSemaphore);
        imshow("info", ip.getProcessedImage());
        imshow("lines", cdst);
        waitKey(0);
        //cout<<"orientation: "<<orientation<<endl;
    }
}