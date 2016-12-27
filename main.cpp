#include "main.hpp"

#define VERSION 1.4

#define SPIspeed 2000000 /* Hz */
#define SPIchannel 0

int main()
{
	cout<<"Version : "<<VERSION<<endl;
	cout<<"Program : SPI test" <<endl;
	cout<<"SPI init result : " << wiringPiSPISetup(SPIchannel, SPIspeed)<<endl;
			
	unsigned char myData = 0x01;
	
	cout<<"Start work..."<<endl;
	
	int SPIresult = 0;
	while(1)
	{
		for (int i = 0 ; i < 8 ; i++)
		{
			SPIresult = wiringPiSPIDataRW(SPIchannel, &(myData << i) , 1);
			cout<<"Write result : "<< SPIresult <<endl;
			(myData << i)
		}
		delay(500);
	}
}
