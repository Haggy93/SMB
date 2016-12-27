#include "main.hpp"

#define VERSION 1.4

static const int SPIspeed = 500000; /* Hz */
static const int SPIchannel = 1;
static const unsigned char SPIdataSize = 4;

int main()
{
	cout<<"Version : "<<VERSION<<endl;
	cout<<"Program : SPI test" <<endl;
	cout<<"SPI init result : " << wiringPiSPISetup(SPIchannel, SPIspeed)<<endl;
			
	//unsigned char SPIdata[SPIdataSize]= {0x00, 0x10, 0x20, 0xff};
	
	unsigned char myData[100];
	
	cout<<"Start work..."<<endl;
	
	myData[0] = 0x76;
	
	int SPIresult = 0;
	while(1)
	{
		delay(500);
		SPIresult = wiringPiSPIDataRW(SPIchannel, myData , 1);
		cout<<"Write result : "<< SPIresult <<endl;
	}
}
