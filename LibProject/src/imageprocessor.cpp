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
    cvtColor(this->inputFrame, this->gray, COLOR_BGR2GRAY);
}

void ImageProcessor::cannyFilter(){

    Canny(this->gray, this->edges, this->lowThreshold, this->highThreshold, this->kernel);

}

void ImageProcessor::hTransform(){

    HoughLines(this->edges, this->lines, 1, CV_PI/180, 200, 0, 0);

}

void ImageProcessor::drawLines(){
    Mat dst;
    cvtColor(this->edges, dst, CV_GRAY2BGR);
    double avgTheta;
    for(size_t i = 0; i < lines.size(); i++){
        float rho = lines[i][0];
        float theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta);
        double b = sin(theta);
        double x0 = a*rho;
        double y0 = b*rho;

        pt1.x = cvRound(x0 + 1000*(-b));
        pt1.y = cvRound(y0 + 1000*(a));
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000*(a));

        line(dst, pt1, pt2, Scalar(0,0,255), 3, CV_AA);
        //avgTheta += lines[i][1];
    }
   // avgTheta /= lines.size();
    //cout<<"Average Theta : " <<avgTheta<<endl;

    imshow("hTransform", dst);
   // waitKey(0);
}

vector<Vec2f> ImageProcessor::getLines(){
    return(this->lines);
}