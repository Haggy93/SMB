#include "main.hpp"

#define VERSION 1.4

#define SPIspeed 500000 /* Hz */
#define SPIchannel 0

int main()
{
	cout<<"Version : "<<VERSION<<endl;
	cout<<"Program : SPI test" <<endl;
	cout<<"SPI init result : " << wiringPiSPISetup(SPIchannel, SPIspeed)<<endl;
	
	u
			
	unsigned char picture1[8] = { 0xAA, 0x01, 0xBC, 0x25, 0xA4, 0x3D, 0x80, 0x55 };
	unsigned char picture2[8] = { 0x55, 0x80, 0x3D, 0xA4, 0x25, 0xBC, 0x01, 0xAA };
	unsigned char picture3[8] = { 0xAA, 0x01, 0xBC, 0x3D, 0xBC, 0x3D, 0x80, 0x55 };
	unsigned char picture4[8] = { 0x55, 0x80, 0x3D, 0xBC, 0x3D, 0xBC, 0x01, 0xAA };
	unsigned char picture5[8] = { 0xAA, 0x01, 0x80, 0x19, 0x98, 0x01, 0x80, 0x55 };
	unsigned char picture6[8] = { 0x55, 0x80, 0x01, 0x98, 0x19, 0x80, 0x01, 0xAA };
									
									
	cout<<"Start work..."<<endl;
	LedMatrixInit(0x02);
	while(1)
	{
		LedMatrixSet(picture1);
		delay(100);
		LedMatrixSet(picture2);
		delay(100);
		LedMatrixSet(picture3);
		delay(100);
		LedMatrixSet(picture4);
		delay(100);
		LedMatrixSet(picture5);
		delay(100);
		LedMatrixSet(picture6);
		delay(100);
		LedMatrixSet(picture3);
		delay(100);
		LedMatrixSet(picture4);
		delay(100);
	}
}
