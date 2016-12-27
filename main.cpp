#include "main.hpp"

#define VERSION 1.4

#define SPIspeed 500000 /* Hz */
#define SPIchannel 0

int main()
{
	cout<<"Version : "<<VERSION<<endl;
	cout<<"Program : SPI test" <<endl;
	cout<<"SPI init result : " << wiringPiSPISetup(SPIchannel, SPIspeed)<<endl;
			
	unsigned char buff[2];
	
	cout<<"Start work..."<<endl;
	
	int SPIresult = 0;

		//Normal operation (shutdown)
		buff[0] = 0x01;
		buff[1] = 0x0C;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
	
		//No decode mode
		buff[0] = 0x00;
		buff[1] = 0x09;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Intensity 19/32
		buff[0] = 0x09;
		buff[1] = 0x0A;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Scan-Limit All
		buff[0] = 0x07;
		buff[1] = 0x0B;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Normal operation (test)
		buff[0] = 0x00;
		buff[1] = 0x0F;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 1
		buff[0] = 0x01;
		buff[1] = 0x01;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 2
		buff[0] = 0x02;
		buff[1] = 0x02;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 3
		buff[0] = 0x04;
		buff[1] = 0x03;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 4
		buff[0] = 0x08;
		buff[1] = 0x04;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 5
		buff[0] = 0x10;
		buff[1] = 0x5;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 6
		buff[0] = 0x20;
		buff[1] = 0x6;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 7
		buff[0] = 0x40;
		buff[1] = 0x07;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 8
		buff[0] = 0x80;
		buff[1] = 0x08;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
}
