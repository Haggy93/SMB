#include "myLCD.hpp"

void LCDsetE(char & data)
{
	data |= 0x04;
}

void LCDreLCDsetE(char & data)
{
	data &= 0xFB;
}

void LCDtoogleEpin(int device)
{
	char readFromPCF;
	readFromPCF = static_cast < char >( wiringPiI2CRead(device) );
	readFromPCF |= 0x08; // set LED bit
	
	LCDsetE(readFromPCF);
	wiringPiI2CWrite(device, readFromPCF);
	usleep(LCD_DELAY);
	
	LCDreLCDsetE(readFromPCF);
	wiringPiI2CWrite(device, readFromPCF);
	usleep(LCD_DELAY);
}

void LCDwaitForBusyFlag(int device)
{
	wiringPiI2CWrite(device, 0xC8);
	while( (wiringPiI2CRead(device)&(0x80)) == 0x00 )
	{}
}

void LCDsendBit(int device, char RS, char RW, char bit)
{
	//STARSZA CZĘŚĆ BITU
	char frame = 0;
	//Ustawienie lini RS i RW oraz wystawienie najstarszej czesci danych
	frame =  (bit & (0xF0)) | (RW<<1) | RS | (1<<3) /*led bit*/;
	LCDsetE(frame);
	wiringPiI2CWrite(device, frame);
	LCDreLCDsetE(frame);
	wiringPiI2CWrite(device, frame);
	LCDwaitForBusyFlag(device);
	
	//MŁODSZA CZĘŚĆ BITU
	frame =  ((bit & (0x0F))<<4) | (RW<<1) | RS | (1<<3) /*led bit*/;
	LCDsetE(frame);
	wiringPiI2CWrite(device, frame);
	LCDreLCDsetE(frame);
	wiringPiI2CWrite(device, frame);
	LCDwaitForBusyFlag(device);
}

void LCDinit(int device)
{
	//pin reset
	char frame = 0x00;
	wiringPiI2CWrite(device, frame);
	usleep(LCD_DELAY);
	
	//Function set 8-bit
	frame = 0x30; 
	for (int i=0 ; i < 3 ; i++)
	{
		wiringPiI2CWrite(device, frame);
		LCDtoogleEpin(device);
	}
	
	//Function set 4-bit
	frame = 0x20;
	wiringPiI2CWrite(device, frame);
	LCDtoogleEpin(device);
	
	LCDsendBit(device, 0, 0, 0x28);
	LCDsendBit(device, 0, 0, 0x08);
	LCDsendBit(device, 0, 0, 0x01);
	LCDsendBit(device, 0, 0, 0x06);
	//END OF INITIALIZAION
	
	//SEND MORE OPTIONS
	LCDsendBit(device, 0, 0, 0b00101000); //Function set
	LCDsendBit(device, 0, 0, 0b00010100); //Cursor or display shift
	LCDsendBit(device, 0, 0, 0b00000110); //Entry mode set
	LCDsendBit(device, 0, 0, 0b00000010); //Return home
	LCDsendBit(device, 0, 0, 0b00000001); //Clear display
	LCDsendBit(device, 0, 0, 0b00001100); //poweron display
}

void LCDwrite(int device, string data)
{

	char buff;
	int length = data.length();

	if (length > 39 /*max size of line*/)
	{
		length = 39;
		cout << "<LCDwrite> Too long message." << endl;
	}

	for (int i = 0 ; i < length ; i++)
	{
		buff = data.at(i);
		LCDsendBit(device, 1, 0, buff);
	}	
}

void LCDsetCursor(int device, char position /*0-39*/, char line)
{
	char buff;
	if (line == 1)
	{
		buff = 0 + position;
		if (buff < 0x00) // first address of DDram in line 0
		{
			buff = 0x00;
		}
		if (buff > 0x27) // last address of DDram in line 0
		{
			buff = 0x27;
		}
		buff |= 0x80; // config bit
		LCDsendBit(device, 0, 0, buff);

	}
	else if (line == 2)
	{
		buff = 0x40 + position;
		if (buff < 0x40) // first address of DDram in  line 1
		{
			buff = 0x40;
		}
		if (buff > 0x67) // last address of DDram in line 1
		{
			buff = 0x67;
		}
		buff |= 0x80; // config bit
		LCDsendBit(device, 0, 0, buff);
	}
	else
	{
		cout << "<LCDsetCURSOR> Wrong line." << endl;
	}
}

void LCDclear(int device, char line)
{
	if (line == 0) // clear both lines
	{
		for (int i  = 1 ; i < 3 ; i++)
		{
			LCDsetCursor( device, 0, (char)(i) );
			for (int j = 0 ; j < LCD_LINE_LENGTH ; j++)
			{
				LCDwrite(device, " ");
			}
		}
	}
	else if (line == 1) // clear first line
	{
		LCDsetCursor( device, 0, (char)(line) );
		for (int i = 0 ; i < LCD_LINE_LENGTH ; i++)
		{
			LCDwrite(device, " ");
		}
	}
	else if (line == 2) // clear second line
	{
		LCDsetCursor( device, 0, (char)(line) );
		for (int i = 0 ; i < LCD_LINE_LENGTH ; i++)
		{
			LCDwrite(device, " ");
		}
	}
	else
	{
		cout<<"<LCDclear> Wrong line."<<endl;
	}
}
