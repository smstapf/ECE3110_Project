#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>

using namespace std;
#define LENGTH 10


int main(int argc, char** argv){

	ifstream camera;
	camera.open("/dev/video1", ios::in);
	if(!camera.is_open()){
		cout<<"Failed to open /dev/video0"<<endl;
	}

	ofstream grab;
	grab.open("grab.raw", ios::out);
	if(!grab.is_open()){
		cout<<"Failed to open grab.raw"<<endl;
	}

	char data[LENGTH];

	while(1){
		camera.getline(data, LENGTH);
		cout<<data<<endl;
	}

	camera.close();
	grab.close();

	return(0);
}
