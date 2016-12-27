#include "main.hpp"

#define VERSION 1.4

#define SPIspeed 2000000 /* Hz */
#define SPIchannel 0

int main()
{
	cout<<"Version : "<<VERSION<<endl;
	cout<<"Program : SPI test" <<endl;
	cout<<"SPI init result : " << wiringPiSPISetup(SPIchannel, SPIspeed)<<endl;
			
	unsigned char myData = 0xF0;
	unsigned char buff;
	
	cout<<"Start work..."<<endl;
	
	int SPIresult = 0;
	while(1)
	{
		buff = 0xff;
		SPIresult = wiringPiSPIDataRW(SPIchannel, &buff , 1);
		cout<<"Write result : "<< SPIresult <<endl;
		
		SPIresult = wiringPiSPIDataRW(SPIchannel, &myData , 1);
		cout<<"Write result : "<< SPIresult <<endl;
		delay(500);
	}
}
