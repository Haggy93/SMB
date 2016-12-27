#include "main.hpp"

#define VERSION 1.4

static const int SPIspeed = 500000; /* Hz */
static const int SPIchannel = 0;
static const unsigned char SPIdataSize = 4;

int main()
{
	wiringPiSetupPhys();
	cout<<"Version : "<<VERSION<<endl;
	cout<<"Program : SPI test" <<endl;
	cout<<"SPI init result : " << wiringPiSPISetup(SPIchannel, SPIspeed)<<endl;
			
	unsigned char SPIdata[4]= {0x00, 0x10, 0x20, 0xff};
	
	unsigned char myBuff = 0b01010101;
	
	cout<<"Start work..."<<endl;
	
	int SPIresult = 0;
	while(1)
	{
		delay(500);
		SPIresult = wiringPiSPIDataRW(SPIchannel, &myBuff , 1);
		cout<<"Write result : "<< SPIresult <<endl;
	}
}
