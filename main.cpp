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
		buff[1] = 0x01;
		buff[0] = 0x0C;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
	
		//No decode mode
		buff[1] = 0x00;
		buff[0] = 0x09;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Intensity 11/32
		buff[1] = 0x05;
		buff[0] = 0x0A;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Scan-Limit All
		buff[1] = 0x07;
		buff[0] = 0x0B;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Normal operation (test)
		buff[1] = 0x00;
		buff[0] = 0x0F;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 1
		buff[1] = 0x0C;
		buff[0] = 0x01;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 2
		buff[1] = 0x1E;
		buff[0] = 0x02;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 3
		buff[1] = 0x3E;
		buff[0] = 0x03;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 4
		buff[1] = 0x7C;
		buff[0] = 0x04;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 5
		buff[1] = 0x3E;
		buff[0] = 0x5;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 6
		buff[1] = 0x1E;
		buff[0] = 0x6;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 7
		buff[1] = 0x0C;
		buff[0] = 0x07;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 8
		buff[1] = 0x00;
		buff[0] = 0x08;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
}
