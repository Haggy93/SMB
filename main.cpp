#include "main.hpp"

#define VERSION 1.0
#define SPIchannel 0
#define SPIspeed 1000000

const unsigned char SPIdataSize = 4;

int main()
{
	cout<<"Version : "<<VERSION<<endl;
	cout<<"SPI test" <<endl;
			
	wiringPiSetup();
	
	uint8_t SPIdata[SPIdataSize] = {'A', 'D' ,'A' , 'M'};
	
	if ( wiringPiSPISetup(SPIchannel, SPIspeed) < 0)
	{
		cout<<"SPI fails...."<<endl;
	}
	else
	{
		out<<"Working..."<<endl;
		while(1)
		{
			delay(500);
			wiringPiSPIDataRW(SPIchannel, SPIdata, SPIdataSize);
		}
	}
}
