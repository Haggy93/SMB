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
	
	uint8_t SPIdata[SPIdataSize] = {'W', 'o' ,'R' , 'k'};
	
	if ( wiringPiSPISetup(SPIchannel, SPIspeed) < 0)
	{
		cout<<"SPI fails...."<<endl;
	}
	else
	{
		while(1)
		{
			delay(500);
			cout<<"Working..."<<endl;
			wiringPiSPIDataRW(SPIchannel, SPIdata, SPIdataSize);
		}
	}
}
