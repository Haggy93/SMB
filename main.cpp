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
			
	//unsigned char SPIdata[SPIdataSize]= {0x00, 0x10, 0x20, 0xff};
	
	uint8_t Mydata = 0xff;
	
	cout<<"Start work..."<<endl;
	
	int SPIresult = 0;
	while(1)
	{
		delay(500);
		SPIresult = wiringPiSPIDataRW(SPIchannel, &Mydata , 1);
		cout<<"Write result : "<< SPIresult <<endl;
	}
}
