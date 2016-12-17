#include "main.hpp"

#define VERSION 1.5

PI_THREAD (pager)
{
	while(1)
	{
		delay(500);
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

int main()
{
	cout<<"Version : "<<VERSION<<endl;
			
	wiringPiSetup ();
		
	int lcd = wiringPiI2CSetup(LCD_Address);
	if (lcd == -1)   
    {
        cout << "Communication with LCD broken!" << endl;
    }
    else
    {
		LCDinit(lcd);
		LCDclear(lcd, BOTH_LINES);
		LCDsetCursor(lcd, 0, FIRST_LINE);
		LCDwrite(lcd, "VERSION 1.5");
		
		int pager_status = piThreadCreate(pager);
		if (pager_status != 0)
		{
			cout<<"Thread doesnt work."<<endl;
		}
		else
		{
			cout<<"myThread starts."<<endl;
		}
		
		while(1)
		{
			/*main loop*/
		}
	}
}
