#include "main.hpp"

#define VERSION 1.5

PI_THREAD (myThread)
{
	while(1)
	{
		delay(1000);
		cout<<"T"<<endl;
	}
}

void myRX(void)
{
	cout<<"Sygnal RX"<<endl;
}

void myTX(void)
{
	cout<<"Sygnal TX"<<endl;
}

int main()
{
	cout<<"Version : "<<VERSION<<endl;
	
			int x = piThreadCreate(myThread);
		if (x != 0)
		{
			cout<<"Thread doesnt work."<<endl;
		}
		else
		{
			cout<<"myThread starts."<<endl;
		}
		
		
	wiringPiSetup ();
	
	cout<<"Rabbit 1"<<endl;
	GSMinit();
	int TX_pin = 16;
	wiringPiISR(TX_pin, INT_EDGE_BOTH , &myRX);
	cout<<"Rabbit 2"<<endl;
	int RX_pin = 15;
	wiringPiISR(TX_pin, INT_EDGE_BOTH , &myTX);
	cout<<"Rabbit 3"<<endl;
	
	
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
		while(1)
		{
			/*
			if(GSMhowManySMS() != 0)
			{
				LCDclear(lcd, BOTH_LINES);
				LCDsetCursor(lcd, 0, FIRST_LINE);
				LCDwrite(lcd, GSMgetNumber(GSMreadSMS(1)));
				LCDsetCursor(lcd, 0, SECOND_LINE);
				LCDwrite(lcd, GSMgetMessage(GSMreadSMS(1)));
				deleteAllSMS();
			}
			*/
		}
	}
}
