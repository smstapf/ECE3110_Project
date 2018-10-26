
/*
 *
 * Header File for ECE 3110 Group 11
 * Balancing an inverted pendulum using image based servoing
 *
 */
#ifndef PENDULUM_H_
#define PENDULUM_H_

#include <stdio.h>
#include <iostream>
#include <string.h>
#include "opencv2/opencv.hpp"

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
        int pin1;
        int pin2;
        bool direction;
        int pwm;

        bool started;
    public:

    Motor();
    ~Motor();

    void setPin1(int pin);
    void setPin2(int pin);
    void setDirection(bool direction);
    void setPwm(int pwm);
    void run();
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

    public:

};
#endif