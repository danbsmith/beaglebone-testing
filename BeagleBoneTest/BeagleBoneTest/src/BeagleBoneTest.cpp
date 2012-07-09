//============================================================================
// Name        : BeagleBoneTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "time.h"
#include "digitalIO.h"

using namespace std;

int main() {
	cout << "Pin exported!" << endl;
	exportPin(48);
	exportPin(7);
	exportPin(38);
	clock_t time = clock();
	clock_t temp_t;
	temp_t = clock();
	int flag = 0;
	digitalWrite(48, 1);
	digitalWrite(7, 1);
	while (time < (15 * CLOCKS_PER_SEC)) {
		temp_t = clock();
		float delay = (float) analogRead(1);
		cout << delay << endl;
		if ((float) (temp_t - time)
				>= delay * (float) (CLOCKS_PER_SEC / 2000)) {
			if (flag == 0) {
				cout << "Set to high!" << endl;
				digitalWrite(38, 1);
				flag = 1;
			} else {
				cout << "Set to low!" << endl;
				digitalWrite(38, 0);
				flag = 0;
			}
			time = clock();
		}
		temp_t = clock();
	}
	digitalWrite(48, 0);
	digitalWrite(7, 0);
	digitalWrite(38, 0);
	unExportPin(48);
	unExportPin(7);
	unExportPin(38);
	return 0;
}
