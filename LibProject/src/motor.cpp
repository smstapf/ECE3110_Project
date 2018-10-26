#include "pendulum.h"

Motor::Motor(){
    std::cout<<"Motor constructor"<<std::endl;
}

Motor::~Motor(){
    std::cout<<"Motor destructor"<<std::endl;
}

void Motor::setPin1(int pin){
    this->pin1 = pin;
}

void Motor::setPin2(int pin){
    this->pin2 = pin;
}

void Motor::setDirection(bool direction){
    this->direction = direction;
}

void Motor::setPwm(int pwm){
    this->pwm = pwm;
}

void Motor::run(){
    this->started = true;
    //TODO
}

void Motor::stop(){
    this->started = false;
    //TODO
}