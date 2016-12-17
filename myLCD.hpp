#ifndef myLCD_hpp
#define myLCD_hpp

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <bitset>

#include <wiringPi.h>
#include <wiringPiI2C.h>

#define LCD_DELAY 1000
#define LCD_LINE_LENGTH 40

#define FIRST_LINE 1
#define SECOND_LINE 2
#define BOTH_LINES 0

using namespace std;

void LCDsetE(char & data);
void LCDreLCDsetE(char & data);
void LCDtoogleEpin(int device);
void LCDwaitForBusyFlag(int device);
void LCDsendBit(int device, char RS, char RW, char bit);
void LCDinit(int device);
void LCDwrite(int device, string data);
void LCDsetCursor(int device, char position, char line);
void LCDclear(int device, char line);

#endif