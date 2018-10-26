#include "pendulum.h"

using namespace std;

Camera::Camera(){
    cout<<"Camera Constructor"<<endl;
    //TODO add camera device number robustness
    this->cap = VideoCapture(0);
    if(!cap.isOpened()){
        cout<<"Failed to open camera"<<endl;
        exit(2);
    }
}

Camera::~Camera(){
    cout<<"Camera Destructor"<<endl;
}

void Camera::captureImage(){
    this->cap >> this->frame;
}

void Camera::saveImage(string fileName){

}

void Camera::displayImage(){
    imshow("test", this->frame);
}

void Camera::streamImage(){
    while(1){
        this->captureImage();
        this->displayImage();
        if(waitKey(30) >= 0){
            return;
        }
    }
}