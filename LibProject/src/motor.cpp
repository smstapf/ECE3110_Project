#include "pendulum.h"

Motor::Motor(){
    std::cout<<"Motor constructor"<<std::endl;
    //init wiring pi
    wiringPiSetup();
    usleep(10);
    //puppuds / io
    //From header definitions
    this->pwm1 = PWM1;
    this->pwm2 = PWM2;
    this->control1 = CONTROL1;
    this->control2 = CONTROL2;

    pinMode(this->control1, OUTPUT);
    pinMode(this->control2, OUTPUT);
    pinMode(this->pwm1, OUTPUT);
    pinMode(this->pwm2, OUTPUT);

    this->direction = CLOCKWISE; //arbiturary
    this->started = false;
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

void Motor::setPwm1(int pwm){
    this->pwm1 = pwm;
}

void Motor::setPwm2(int pwm){
    this->pwm2 = pwm;
}

//Put in a loop somewhere
void Motor::run(){
    //TODO
    struct itimerspec pwm1Timer; //For PWM1 Timer
    struct itimerspec pwm2Timer; //For PWM2 Timer

    //Create the timer
    int timer_fd = timerfd_create(CLOCK_MONOTONIC, 0);
	 if(timer_fd == -1) {
		 	printf("Error creating timer");
		 	exit(0);
	 }

    while(this->started){
        if(this->direction = CLOCKWISE){
            /*
	        timerspec.it_interval.tv_sec = 0;
	        timerspec.it_interval.tv_nsec = 1000000;
	        timerspec.it_value.tv_sec = 0;
	        timerspec.it_value.tv_nsec = 1000000;
	        if(timerfd_settime(timer_fd,0,&timerspec,NULL) == -1) {
	 	        printf("Error starting timer");
	 	        exit(0);
	        }
            */
        }else{

        }
    }
   
}

void Motor::start(){
    this->start = true;
}

void Motor::stop(){
    this->start = false;
    //TODO
}