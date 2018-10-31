
/*
 *
 * Header File for ECE 3110 Group 11
 * Balancing an inverted pendulum using image based servoing
 *
 */
#ifndef PENDULUM_H_
#define PENDULUM_H_
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <thread>
#include <semaphore.h>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <wiringPi.h>

#define CONTROL1 1
#define CONTROL2 4
#define PWM1 5
#define PWM2 6
#define CLOCKWISE 0
#define C_CLOCKWISE 1

using namespace cv;
using namespace std;

class Accelerometer{
    private:

    public:

    Accelerometer();
    ~Accelerometer();

};



class Motor{
    private:
        int pwm1;
        int control1;
        int pwm2;
        int control2;
        bool direction;

        bool start;
    public:

    Motor();
    ~Motor();

    void setPin1(int pin);
    void setPin2(int pin);
    void setDirection(bool direction);
    void setPwm1(int pwm);
    void setPwm2(int pwm);
    void run();
    void start();
    void stop();


};

class Camera{
    private:
        VideoCapture cap;
        Mat frame;
    
    public:

    Camera();
    ~Camera();

    Mat getImage();

    void captureImage();
    void saveImage(string fileName);
    void displayImage();
    void streamImage();

    
};

class ImageProcessor{
    private:                                         
        Mat inputFrame;
        Mat gray;
        Mat edges;
        Mat outputFrame;

        double lowThreshold;
        double highThreshold;
        int kernel;
        vector<Vec2f> lines;

    public:

        ImageProcessor();
        ~ImageProcessor();


        void setLowThresh(double thresh);
        void setHighThresh(double thresh);
        void setKernel(int kernel);
        
        void loadImage(Mat frame);

        Mat getProcessedImage();
        vector<Vec2f> getLines();
        
        void toGray();
        void cannyFilter();
        void hTransform();
        void drawLines();

};
#endif
