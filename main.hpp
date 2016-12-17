#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <bitset>

#include "myLCD.hpp"
#include "myGSM.hpp"

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <wiringSerial.h>

using namespace std;
const char LCD_Address = 0x27;

void myTX(void);
void myRX(void);