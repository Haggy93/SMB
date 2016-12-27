#include "main.hpp"

#define VERSION 1.2

static const int SPIspeed = 500000; /* Hz */
static const int SPIchannel = 0;
static const unsigned char SPIdataSize = 4;

int main()
{
	wiringPiSetup();
	cout<<"Version : "<<VERSION<<endl;
	cout<<"Program : SPI test" <<endl;
	cout<<"SPI init result :" << wiringPiSPISetup(SPIchannel, SPIspeed)<<endl;
			
	unsigned char SPIdata[SPIdataSize]= {'a','n','k','a'};
	
	cout<<"Start work..."<<endl;
	
	while(1)
	{
		delay(100);
		wiringPiSPIDataRW(SPIchannel, SPIdata, 1);
	}
}
