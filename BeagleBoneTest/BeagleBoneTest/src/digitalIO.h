/*
 * digitalIO.h
 *
 *  Created on: Jun 30, 2012
 *      Author: daniel
 */

#ifndef DIGITALIO_H_
#define DIGITALIO_H_

#include <fstream>
#include <iostream>
#include "stdlib.h"

void digitalWrite(int pin, int value);
int digitalRead(int pin);
void exportPin(int pin);
void unExportPin(int pin);
void enablePWMMUX(int pin);
void setPWM(int pin1, int pin2, long int val, long int freq, int run);
#endif /* DIGITALIO_H_ */
