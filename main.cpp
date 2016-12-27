#include "main.hpp"

#define VERSION 1.2
#define SPIchannel 0
#define SPIspeed 500000

const unsigned char SPIdataSize = 4;

int main()
{
	cout<<"Version : "<<VERSION<<endl;
	cout<<"SPI test" <<endl;
			
	wiringPiSetup();
	
	uint8_t SPIdata[SPIdataSize]= {'a','n','k','a'};
	
	cout<<"Working..."<<endl;
	
	while(1)
	{
		delay(500);
		if ( wiringPiSPISetup(SPIchannel, SPIspeed) < 0)
		{
			cout<<"Nie wysłano"<<endl;
		}
		else
		{
			cout<<"Wysłano"<<endl;
			wiringPiSPIDataRW(SPIchannel, SPIdata, SPIdataSize);
		}
	}
}
