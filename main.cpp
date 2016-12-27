#include "main.hpp"

#define VERSION 1.4

#define SPIspeed 500000 /* Hz */
#define SPIchannel 0

void LedMatrixInit(unsigned char myIntens)
{
	unsigned char buff[2];
	
	//Normal operation (shutdown)
	buff[0] = 0x0C;
	buff[1] = 0x01;
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x0C. "<<endl;
	}
	
	//No decode mode
	buff[0] = 0x09;
	buff[1] = 0x00;
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x09. "<<endl;
	}
	
	//Intensity 5/32
	buff[0] = 0x0A;
	buff[1] = myIntens;
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x0A. "<<endl;
	}
	
	//Scan-Limit All
	buff[0] = 0x0B;
	buff[1] = 0x07;
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x0B. "<<endl;
	}
	
	//Normal operation (test)
	buff[0] = 0x0F;
	buff[1] = 0x00;
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x0F. "<<endl;
	}
}

void LedMatrixSet(unsigned char *data)
{
	//Segment 1
	buff[0] = 0x01; //Adres
	buff[1] = data[0];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x01. "<<endl;
	}
		
	//Segment 2
	buff[0] = 0x02; //Adres
	buff[1] = data[1];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x02. "<<endl;
	}
		
	//Segment 3
	buff[0] = 0x03; //Adres
	buff[1] = data[2];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x03. "<<endl;
	}
		
	//Segment 4
	buff[0] = 0x04; //Adres
	buff[1] = data[3];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x04. "<<endl;
	}
		
		//Segment 5
	buff[0] = 0x5; //Adres
	buff[1] = data[4];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x05. "<<endl;
	}
		
	//Segment 6
	buff[0] = 0x6; //Adres
	buff[1] = data[5];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x06. "<<endl;
	}
	
	//Segment 7 
	buff[0] = 0x07; //Adres
	buff[1] = data[6];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x07. "<<endl;
	}
		
	//Segment 8
	buff[0] = 0x08; //Adres
	buff[1] = data[7];
	if ( wiringPiSPIDataRW(SPIchannel, buff , 2) == -1 )
	{
		cout<<"Init fails. Register 0x08. "<<endl;
	}
}

int main()
{
	cout<<"Version : "<<VERSION<<endl;
	cout<<"Program : SPI test" <<endl;
	cout<<"SPI init result : " << wiringPiSPISetup(SPIchannel, SPIspeed)<<endl;
			
	unsigned char picture[8] = { 0x13,
									0xF3,
									0x13,
									0x50,
									0x03,
									0x51,
									0x58,
									0x51
									};
	cout<<"Start work..."<<endl;
	LedMatrixInit(0x02);
	LedMatrixSet(picture);
}
