#include "pendulum.h"


ImageProcessor::ImageProcessor(){
    cout<<"ImageProcessor Constructor"<<endl;
}

ImageProcessor::~ImageProcessor(){
    cout<<"ImageProcessor Destructor"<<endl;
}

void ImageProcessor::setLowThresh(double thresh){
    this->lowThreshold = thresh;
}

void ImageProcessor::setHighThresh(double thresh){
    this->highThreshold = thresh;
}

void ImageProcessor::setKernel(int kernel){
    this->kernel = kernel;
}

void ImageProcessor::loadImage(Mat frame){
    this->inputFrame = frame;
    this->outputFrame = frame;
}

Mat ImageProcessor::getProcessedImage(){
    return(this->outputFrame);
}


void ImageProcessor::toGray(){
    cvtColor(this->inputFrame, this->outputFrame, COLOR_BGR2GRAY);
}

void ImageProcessor::canny(){

    Canny(this->outputFrame, this->outputFrame, this->lowThreshold, this->highThreshold, this->kernel);

}