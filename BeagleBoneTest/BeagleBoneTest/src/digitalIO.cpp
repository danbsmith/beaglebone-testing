#include <fstream>
#include <iostream>
#include "stdlib.h"
#include "time.h"
#include "digitalIO.h"
using namespace std;

void digitalWrite(int pin, int value) {
	ofstream valuepin;
	ofstream directionpin;
	char initpath[] = { '/', 's', 'y', 's', '/', 'c', 'l', 'a', 's', 's', '/',
			'g', 'p', 'i', 'o', '/', 'g', 'p', 'i', 'o' };
	char dfpath[] = { '/', 'd', 'i', 'r', 'e', 'c', 't', 'i', 'o', 'n' };
	char vfpath[] = { '/', 'v', 'a', 'l', 'u', 'e' };
	if (pin < 10) {
		char valuefilename[28] = { '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0' };
		char directionfilename[32] = { '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
		char temppin[2] = { "0" };
		for (int i = 0; i <= 19; i++) {
			valuefilename[i] = initpath[i];
			directionfilename[i] = initpath[i];
		}
		snprintf(temppin, 2, "%d", pin);
		valuefilename[20] = temppin[0];
		directionfilename[20] = temppin[0];
		int j = 0;
		for (int i = 21; i <= 26; i++) {
			valuefilename[i] = vfpath[j];
			j++;
		}
		j = 0;
		for (int i = 21; i <= 30; i++) {
			directionfilename[i] = dfpath[j];

		}
		directionpin.open(directionfilename, ios::trunc);
		valuepin.open(valuefilename, ios::trunc);
	}
	if (pin >= 10 && pin < 100) {
		char valuefilename[29] = { '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0' };
		char directionfilename[33] = { '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
		char temppin[3];
		for (int i = 0; i <= 19; i++) {
			valuefilename[i] = initpath[i];
			directionfilename[i] = initpath[i];
		}
		snprintf(temppin, 3, "%d", pin);
		valuefilename[20] = temppin[0];
		directionfilename[20] = temppin[0];
		valuefilename[21] = temppin[1];
		directionfilename[21] = temppin[1];
		int j = 0;
		for (int i = 22; i <= 27; i++) {
			valuefilename[i] = vfpath[j];
			j++;
		}
		j = 0;
		for (int i = 22; i <= 31; i++) {
			directionfilename[i] = dfpath[j];
			j++;
		}
		directionpin.open(directionfilename, ios::trunc);
		valuepin.open(valuefilename);
		for (int k = 0; k < 33; k++) {
		}
	}
	if (pin >= 100) {
		char temppin[3];
		char valuefilename[30] = { '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0' };
		char directionfilename[34] = { '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
		for (int i = 0; i <= 19; i++) {
			valuefilename[i] = initpath[i];
			directionfilename[i] = initpath[i];
			cout << initpath[i];
		}
		snprintf(temppin, 3, "%d", pin);
		valuefilename[20] = temppin[0];
		directionfilename[20] = temppin[0];
		valuefilename[21] = temppin[1];
		directionfilename[21] = temppin[1];
		valuefilename[22] = temppin[2];
		directionfilename[22] = temppin[2];
		int j = 0;
		for (int i = 23; i <= 28; i++) {
			valuefilename[i] = vfpath[j];
			j++;
		}
		for (int i = 23; i <= 32; i++) {
			int j = 0;
			directionfilename[i] = dfpath[j];
			j++;
		}
		directionpin.open(directionfilename, ios::trunc);
		valuepin.open(valuefilename, ios::trunc);
	}
	directionpin << "out";
	directionpin.close();
	valuepin << value;
	//cout << value << endl;
	valuepin.close();
}

int digitalRead(int pin) {
	ifstream valuepin;
	ofstream directionpin;
	char initpath[] = { '/', 's', 'y', 's', '/', 'c', 'l', 'a', 's', 's', '/',
			'g', 'p', 'i', 'o', '/', 'g', 'p', 'i', 'o' };
	char dfpath[] = { '/', 'd', 'i', 'r', 'e', 'c', 't', 'i', 'o', 'n' };
	char vfpath[] = { '/', 'v', 'a', 'l', 'u', 'e' };
	if (pin < 10) {
		char valuefilename[28] = { '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0' };
		char directionfilename[32] = { '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
		char temppin[2] = { "0" };
		for (int i = 0; i <= 19; i++) {
			valuefilename[i] = initpath[i];
			directionfilename[i] = initpath[i];
		}
		snprintf(temppin, 2, "%d", pin);
		valuefilename[20] = temppin[0];
		directionfilename[20] = temppin[0];
		int j = 0;
		for (int i = 21; i <= 26; i++) {
			valuefilename[i] = vfpath[j];
			j++;
		}
		j = 0;
		for (int i = 21; i <= 30; i++) {
			directionfilename[i] = dfpath[j];

		}
		directionpin.open(directionfilename, ios::trunc);
		valuepin.open(valuefilename, ios::trunc);
	}
	if (pin >= 10 && pin < 100) {
		char valuefilename[29] = { '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0' };
		char directionfilename[33] = { '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
		char temppin[3];
		for (int i = 0; i <= 19; i++) {
			valuefilename[i] = initpath[i];
			directionfilename[i] = initpath[i];
		}
		snprintf(temppin, 3, "%d", pin);
		valuefilename[20] = temppin[0];
		directionfilename[20] = temppin[0];
		valuefilename[21] = temppin[1];
		directionfilename[21] = temppin[1];
		int j = 0;
		for (int i = 22; i <= 27; i++) {
			valuefilename[i] = vfpath[j];
			j++;
		}
		j = 0;
		for (int i = 22; i <= 31; i++) {
			directionfilename[i] = dfpath[j];
			j++;
		}
		directionpin.open(directionfilename, ios::trunc);
		valuepin.open(valuefilename);
		for (int k = 0; k < 33; k++) {
		}
	}
	if (pin >= 100) {
		char temppin[3];
		char valuefilename[30] = { '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0' };
		char directionfilename[34] = { '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
				'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
		for (int i = 0; i <= 19; i++) {
			valuefilename[i] = initpath[i];
			directionfilename[i] = initpath[i];
			cout << initpath[i];
		}
		snprintf(temppin, 3, "%d", pin);
		valuefilename[20] = temppin[0];
		directionfilename[20] = temppin[0];
		valuefilename[21] = temppin[1];
		directionfilename[21] = temppin[1];
		valuefilename[22] = temppin[2];
		directionfilename[22] = temppin[2];
		int j = 0;
		for (int i = 23; i <= 28; i++) {
			valuefilename[i] = vfpath[j];
			j++;
		}
		for (int i = 23; i <= 32; i++) {
			int j = 0;
			directionfilename[i] = dfpath[j];
			j++;
		}
		directionpin.open(directionfilename, ios::trunc);
		valuepin.open(valuefilename, ios::in);
	}
	int input;
	directionpin << "in";
	valuepin >> input;
	directionpin.close();
	valuepin.close();
	return input;
}

int analogRead(int pin) {
	ifstream valuepin;
	int input;
	char initpath[] = { '/', 's', 'y', 's', '/', 'd', 'e', 'v', 'i', 'c', 'e',
			's', '/', 'p', 'l', 'a', 't', 'f', 'o', 'r', 'm', '/', 'o', 'm',
			'a', 'p', '/', 't', 's', 'c', '/', 'a', 'i', 'n' };
	char valuefilename[36];
	char temppin[2] = { "0" };
	for (int i = 0; i <= 33; i++) {
		valuefilename[i] = initpath[i];
	}
	snprintf(temppin, 2, "%d", pin);
	valuefilename[34] = temppin[0];
	valuepin.open(valuefilename);
	usleep(100);
	valuepin >> input;
	for (int i = 0; i < 33; i++) {
	}
	cout << input << endl;
	valuepin.close();
	return input;
}

void exportPin(int pin) {
	ofstream exportpin("/sys/class/gpio/export", ios::trunc);
	exportpin << pin;
	exportpin.close();
}

void unExportPin(int pin) {
	ofstream unexportpin("/sys/class/gpio/unexport", ios::trunc);
	unexportpin << pin;
	unexportpin.close();
}
