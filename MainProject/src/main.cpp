#include "pendulum.h"

using namespace std;


int main(int argc, char**  argv){
    Motor motor = Motor();
    Camera camera = Camera();
    Accelerometer accelerometer = Accelerometer();

    camera.streamImage();
    cout<<"test"<<endl;

    return(0);
}