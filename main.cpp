#include "main.hpp"

#define VERSION 1.4

int main()
{
	cout<<"Version : "<<VERSION<<endl;
	GSMinit();
	int lcd = wiringPiI2CSetup(LCD_Address);
	if (lcd == -1)   
    {
        cout << "Communication with LCD broken!" << endl;
    }
    else
    {
		LCDinit(lcd);
		while(1)
		{
			if(GSMhowManySMS() != 0)
			{
				LCDclear(lcd, 0);
				LCDsetCursor(lcd, 0, 1);
				LCDwrite(lcd, GSMgetDate(GSMreadSMS(1)));
				LCDsetCursor(lcd, 0, 2);
				LCDwrite(lcd, GSMgetMessage(GSMreadSMS(1)));
				deleteAllSMS();
			}
		}
	}
	
	//string numer = "+48723320133";
	//string wiadomosc = "*****";
	//sendSMS(numer, wiadomosc);
}