#ifndef myGSM_hpp
#define myGSM_hpp

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <string.h>

#include <wiringPi.h>
#include <wiringSerial.h>

#define SHOW_RAPORTS 0

using namespace std;

void isGSMok(int phoneID);
void GSMtransACK(int phoneID);
string GSMreadANS(int phoneID);
void sendSMS(string myPhone, string message);
void GSMinit();
string GSMreadSMS(int number);
void deleteAllSMS();
string GSMgetStatus(string SMS);
string GSMgetNumber(string SMS);
string GSMgetDate(string SMS);
string GSMgetTime(string SMS);
string GSMgetMessage(string SMS);
int GSMhowManySMS();

#endif