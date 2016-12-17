#include "main.hpp"

#define VERSION 1.5

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
		LCDclear(lcd, 0);
		LCDsetCursor(lcd, 0, 1);
		LCDwrite(lcd, "VERSION 1.5");
		while(1)
		{
			if(GSMhowManySMS() != 0)
			{
				LCDclear(lcd, 0);
				LCDsetCursor(lcd, 0, 1);
				LCDwrite(lcd, GSMgetNumber(GSMreadSMS(1)));
				LCDsetCursor(lcd, 0, 2);
				LCDwrite(lcd, GSMgetMessage(GSMreadSMS(1)));
				deleteAllSMS();
			}
		}
		cout<<"Bla bla bla"<<endl;
	}
}