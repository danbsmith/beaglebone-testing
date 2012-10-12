//============================================================================
// Name        : BeagleBoneTest.cpp
// Author      : Daniel Smith
// Version     :
// Copyright   : Your copyright notice
// Description : Test Program for C++ on BeagleBone
//============================================================================

#include <iostream>
#include <fstream>
#include "time.h"
#include "digitalIO.h"

using namespace std;

int main() {
	clock_t time = clock();
	clock_t temp_t;
	temp_t = clock();
	enablePWMMUX(1);
	setPWM(0, 1, 50, 1000, 1);
	while (time < (15 * CLOCKS_PER_SEC)) {
		temp_t = clock();
		//float delay = (float) analogRead(1);
		//cout << delay << endl;
		time = clock();
		temp_t = clock();
	}
	setPWM(0, 1, 0, 1, 0);
	return 0;
}
