
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
        

    public:

    Motor();
    ~Motor();

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