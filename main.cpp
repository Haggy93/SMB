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
		buff[0] = 0x0C;
		buff[1] = 0x01;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
	
		//No decode mode
		buff[0] = 0x09;
		buff[1] = 0x00;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Intensity 5/32
		buff[0] = 0x0A;
		buff[1] = 0x02;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Scan-Limit All
		buff[0] = 0x0B;
		buff[1] = 0x07;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Normal operation (test)
		buff[0] = 0x0F;
		buff[1] = 0x00;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 1
		buff[0] = 0x01; //Adres
		buff[1] = 0x00;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 2
		buff[0] = 0x02; //Adres
		buff[1] = 0x10;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 3
		buff[0] = 0x03; //Adres
		buff[1] = 0x28;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 4
		buff[0] = 0x04; //Adres
		buff[1] = 0x44;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 5
		buff[0] = 0x5; //Adres
		buff[1] = 0x7C;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 6
		buff[0] = 0x6; //Adres
		buff[1] = 0x7C;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 7 
		buff[0] = 0x07; //Adres
		buff[1] = 0x44;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
		
		//Segment 8
		buff[0] = 0x08; //Adres
		buff[1] = 0x44;
		SPIresult = wiringPiSPIDataRW(SPIchannel, buff , 2);
		cout<<"Write result : "<< SPIresult <<endl;
}
