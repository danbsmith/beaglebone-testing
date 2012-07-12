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

/** Ubuntu does not have the kernel modifications to use analog input pins *
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
 */

void enablePWMClock() {
	// Just a placeholder
	// TODO: Learn to set registers from C++
}

void setPWM(int pin1, int pin2, int duty, int freq) {
//frequency will be used to adjust motors (f = 1/lambda, where lambda ranges from 1000 to 2000 us)
	ofstream freqpin;
	ofstream dutypercentpin;
	char initpath[] = { '/', 's', 'y', 's', '/', 'c', 'l', 'a', 's', 's', '/',
			'p', 'w', 'm', '/', 'e', 'h', 'r', 'p', 'w', 'm', '.' };
	char dfpath[] = { '/', 'd', 'u', 't', 'y', '_', 'p', 'e', 'r', 'c', 'e',
			'n', 't' };
	char ffpath[] =
			{ '/', 'p', 'e', 'r', 'i', 'o', 'd', '_', 'f', 'r', 'e', 'q' };
	char dutyfilename[39] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
			'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
			'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
			'0', '0' };
	char frequencyfilename[38] = { '0', '0', '0', '0', '0', '0', '0', '0', '0',
			'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
			'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
			'0', '0' };
	char temppin1[2] = { "0" };
	char temppin2[2] = { "0" };
	for (int i = 0; i <= 21; i++) {
		dutyfilename[i] = initpath[i];
		frequencyfilename[i] = initpath[i];
	}
	snprintf(temppin1, 2, "%d", pin1);
	dutyfilename[22] = temppin1[0];
	frequencyfilename[22] = temppin1[0];
	dutyfilename[23] = ':';
	frequencyfilename[23] = ':';
	snprintf(temppin2, 2, "%d", pin2);
	dutyfilename[24] = temppin2[0];
	frequencyfilename[24] = temppin2[0];
	int j = 0;
	for (int i = 25; i <= 38; i++) {
		dutyfilename[i] = dfpath[j];
		j++;
	}
	j = 0;
	for (int i = 25; i <= 37; i++) {
		frequencyfilename[i] = ffpath[j];
		j++;
	}
	dutypercentpin.open(dutyfilename, ios::trunc);
	freqpin.open(frequencyfilename, ios::trunc);
	dutypercentpin << 0;
	dutypercentpin.close();
	freqpin << freq;
	dutypercentpin.open(dutyfilename, ios::trunc);
	dutypercentpin << duty;
	dutypercentpin.close();
	freqpin.close();
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
