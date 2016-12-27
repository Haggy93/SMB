#include "main.hpp"

#define VERSION 1.0
#define SPIchannel 0
#define SPIspeed 500000

int main()
{
	cout<<"Version : "<<VERSION<<endl;
	cout<<"SPI test" <<endl;
			
	wiringPiSetup();
	
	unsigned char SPIdata[3] = {0xF0 , 0xAA, 0xFF};
	
	wiringPiSPISetup(SPIchannel, SPIspeed);
		
	while(1)
	{
		delay(1000);
		cout<<"Working..."<<endl;
		wiringPiSPIDataRW(SPIchannel, SPIdata, 3);
	}
}
