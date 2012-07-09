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
int analogRead(int pin);
#endif /* DIGITALIO_H_ */