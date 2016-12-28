#ifndef myLedMatrix_hpp
#define myLedMatrix_hpp

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <string.h>

#include <wiringPi.h>
#include <wiringPiSPI.h>

//Defines list
#define Address_NoOp 0x00

#define Address_Digit0 0x01
#define Address_Digit1 0x02
#define Address_Digit2 0x03
#define Address_Digit3 0x04
#define Address_Digit4 0x05
#define Address_Digit5 0x06
#define Address_Digit6 0x07
#define Address_Digit7 0x08

#define Address_DecodeMode 0x09
#define Address_Intensity 0x0A
#define Address_ScanLimit 0x0B
#define Address_Shutdown 0x0C
#define Address_DisplayTest 0x0F

using namespace std;

void LedMatrixInit(unsigned char myIntens);
void LedMatrixSet(unsigned char *data);

#endif