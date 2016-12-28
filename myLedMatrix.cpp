#include "myLedMatrix.hpp"

void LedMatrixInit(unsigned char myIntens)
{
	unsigned char buff[2];
	
	//Normal operation (shutdown)
	buff[0] = Address_Shutdown;
	buff[1] = 0x01;
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x0C. "<<endl;
	}
	
	//No decode mode
	buff[0] = Address_DecodeMode;
	buff[1] = 0x00;
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x09. "<<endl;
	}
	
	//Intensity 5/32
	buff[0] = Address_Intensity;
	buff[1] = myIntens;
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x0A. "<<endl;
	}
	
	//Scan-Limit All
	buff[0] = Address_ScanLimit;
	buff[1] = 0x07;
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x0B. "<<endl;
	}
	
	//Normal operation (test)
	buff[0] = Address_DisplayTest;
	buff[1] = 0x00;
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x0F. "<<endl;
	}
}

void LedMatrixSet(unsigned char *data)
{
	unsigned char buff[2];
	
	//Segment 1
	buff[0] = Address_Digit0;
	buff[1] = data[0];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x01. "<<endl;
	}
		
	//Segment 2
	buff[0] = Address_Digit1;
	buff[1] = data[1];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x02. "<<endl;
	}
		
	//Segment 3
	buff[0] = Address_Digit2;
	buff[1] = data[2];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x03. "<<endl;
	}
		
	//Segment 4
	buff[0] = Address_Digit3;
	buff[1] = data[3];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x04. "<<endl;
	}
		
		//Segment 5
	buff[0] = Address_Digit4;
	buff[1] = data[4];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x05. "<<endl;
	}
		
	//Segment 6
	buff[0] = Address_Digit5;
	buff[1] = data[5];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x06. "<<endl;
	}
	
	//Segment 7 
	buff[0] = Address_Digit6;
	buff[1] = data[6];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x07. "<<endl;
	}
		
	//Segment 8
	buff[0] = Address_Digit7;
	buff[1] = data[7];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x08. "<<endl;
	}
}