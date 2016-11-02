#include "myGSM.hpp"

void isGSMok(int phoneID)
{
	if (phoneID != -1)
	{
		#if SHOW_RAPORTS == 1
			cout<<"Connected to GMS module."<<endl;
		#endif
	}
	else
	{
		cout<<"Cannot establish a UART communication."<<endl;
	}
}

void GSMtransACK(int phoneID)
{
	string checkOK = "";
	char buff;
	
	while( checkOK.find("OK") == string::npos )
	{	
		buff = serialGetchar(phoneID);
		if ( buff != (-1) )
		{
			checkOK += buff;
		}
	}
	#if SHOW_RAPORTS == 1
		cout<<checkOK<<endl;
	#endif
}

string GSMreadANS(int phoneID)
{
	char buff;
	string data;
	while( data.find("OK") == string::npos )
	{	
		buff = serialGetchar(phoneID);
		if ( buff != (-1) )
		{
			data += buff;
		}
	}
	return data;
}

void sendSMS(string myPhone, string message)
{
	int myGSM = serialOpen("/dev/ttyAMA0", 9600); //Remmember about permission : sudo chmod a+rw /dev/ttyAMA0
	isGSMok(myGSM);
	
	cout<<"Sending :\n"<<message<<"\nto : "<<myPhone<<endl;
	
	//Przygotowanie ramki zawierajacej numer na ktory chcemy wyslac
	string out = "AT+CMGS=\"" + myPhone + "\"\x0D";
	serialPuts(myGSM, out.c_str());
	
	//Czekamy az GSM odpowie nam znakiem '>'
	while(serialGetchar(myGSM) != '>')
	{}
	
	//Potem wpisujemy i wysylamy komunikat
	out = message + "\x1A";
	serialPuts(myGSM, out.c_str());
	
	GSMtransACK(myGSM);
	serialClose(myGSM);
}

void GSMinit()
{
	int myGSM = serialOpen("/dev/ttyAMA0", 9600); //Remmember about permission : sudo chmod a+rw /dev/ttyAMA0
	isGSMok(myGSM);
	serialPuts(myGSM, "AT+CMGF=1\x0D"); // ustawia tryb tekstowy
	GSMtransACK(myGSM);
	serialPuts(myGSM, "AT+CSCS=\"GSM\"\x0D"); // tryb GSM
	GSMtransACK(myGSM);
	serialPuts(myGSM, "AT+CNMI=1,0,0,0,0\x0D"); // tryb GSM
	GSMtransACK(myGSM);
	serialClose(myGSM);
}

string GSMgetStatus(string SMS)
{
	string status = "Nope";
	
	int found = SMS.find("READ");
	if (found != string::npos)
	{
		status = "Przeczytano";
	}
	
	found = SMS.find("UNREAD");
	if (found != string::npos)
	{
		status = "Nieprzeczytano";
	}
	return status;
}

string GSMgetNumber(string SMS)
{
	string number = "Nope";
	
	int found = SMS.find("+48");
	if (found != string::npos)
	{
		number = SMS.substr(found, 12); // length of number
	}
	return number;
}

string GSMgetDate(string SMS)
{
	string date = "Nope";
	
	int buff = SMS.find("+48");
	if (buff != string::npos)
	{
		buff += 12; // length of number
		buff = SMS.find_first_of("0123456789", buff);
		date = SMS.substr(buff, 8);
	}
	return date;
}

string GSMgetTime(string SMS)
{
	string time = "Nope";
	int buff = SMS.find("+48");
	if (buff != string::npos)
	{
		buff += 12; // length of number
		buff = SMS.find_first_of("0123456789", buff);
		buff += 8; // length of date
		buff = SMS.find_first_of("0123456789", buff);
		time = SMS.substr(buff, 8);
	}
	return time;
}

string GSMgetMessage(string SMS)
{
	string message = "Nope";
	
	int found = SMS.find_last_of("\"");
	if (found != string::npos)
	{
		int length_of_message = SMS.length() - found;
		message = SMS.substr(found+3 /*without "*/, length_of_message);
	}
	found = message.find_first_of("\n");
	return message.substr(0, found-1); //delete enters
}

int GSMhowManySMS()
{
	int myGSM = serialOpen("/dev/ttyAMA0", 9600); //Remmember about permission : sudo chmod a+rw /dev/ttyAMA0
	isGSMok(myGSM);
	
	serialPuts(myGSM, "AT+CPMS?\x0D");
	string answer = GSMreadANS(myGSM);
	
	int Comma = answer.find_first_of(",");
	
	answer = answer.erase(0,(Comma+1)); // delete substring with comma together
 	
	Comma = answer.find_first_of(",");
	
	int storedMessages = atoi((answer.substr(0, Comma)).c_str());
	
	serialClose(myGSM);
	return storedMessages;
}

string GSMreadSMS(int number)
{		
	int myGSM = serialOpen("/dev/ttyAMA0", 9600); //Remmember about permission : sudo chmod a+rw /dev/ttyAMA0
	isGSMok(myGSM);
	
	//if too much
	number = number>25?25:number; // 25 - max amount of SMS
	//if not enougth
	number = number<1?1:number; // it cant be lower than 1
	
	serialPuts(myGSM, ("AT+CMGR=" + to_string(number) + "\x0D").c_str());
	string answer = GSMreadANS(myGSM);
	
	serialClose(myGSM);
	return answer;
}

void deleteAllSMS()
{
	int myGSM = serialOpen("/dev/ttyAMA0", 9600); //Remmember about permission : sudo chmod a+rw /dev/ttyAMA0
	isGSMok(myGSM);
	serialPuts(myGSM, "AT+CMGD=1,4\x0D");
	GSMtransACK(myGSM);
	serialClose(myGSM);
}