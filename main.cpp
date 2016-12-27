#include "main.hpp"

#define VERSION 1.0
#define SPIchannel 0
#define SPIspeed 500000

const unsigned char SPIdataSize = 1;

int main()
{
	cout<<"Version : "<<VERSION<<endl;
	cout<<"SPI test" <<endl;
			
	wiringPiSetup();
	
	uint8_t SPIdata= 70;
	
	cout<<"Working..."<<endl;
	while(1)
	{
		delay(500);
		if ( wiringPiSPISetup(SPIchannel, SPIspeed) < 0)
		{
			cout<<"Wysłano"<<endl;
			wiringPiSPIDataRW(SPIchannel, &SPIdata, SPIdataSize);
		}
		else
		{
			cout<<"Nie wysłano"<<endl;
		}
	}
}
