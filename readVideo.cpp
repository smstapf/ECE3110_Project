#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;
#define LENGTH 1280*720
int main(int argc, char** argv){
	
	FILE *camera, *grab;
	camera = fopen("/dev/video1", "rb");
	grab = fopen("grab.raw", "wb");
	float data[LENGTH];

	fread(data, sizeof(data[0]), LENGTH, camera);
	fwrite(data, sizeof(data[0]), LENGTH, grab);
	fclose(camera);
	fclose(grab);

	return(0);
}
