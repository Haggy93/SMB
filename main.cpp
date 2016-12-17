#include "main.hpp"

#define VERSION 1.5

PI_THREAD (myThread)
{
	cout<<"bla bla bla"<<endl;
}

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
		
		int x = piThreadCreate(myThread);
		
		LCDclear(lcd, BOTH_LINES);
		LCDsetCursor(lcd, 0, FIRST_LINE);
		LCDwrite(lcd, "VERSION 1.5");
		while(1)
		{
			if(GSMhowManySMS() != 0)
			{
				LCDclear(lcd, BOTH_LINES);
				LCDsetCursor(lcd, 0, FIRST_LINE);
				LCDwrite(lcd, GSMgetNumber(GSMreadSMS(1)));
				LCDsetCursor(lcd, 0, SECOND_LINE);
				LCDwrite(lcd, GSMgetMessage(GSMreadSMS(1)));
				deleteAllSMS();
			}
		}
	}
}
